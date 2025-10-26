// --------------------------------------------------------------
// Title      : LED Mode Control with OLED Display (Task A)
// Author     : Ayesha Iftikhar
// Reg. No.   : 23-NTU-CS-1021
// Section    : BSCS 5th (A)
// Course     : Internet of Things (IoT)
// Instructor : [Your Teacher’s Name]
// Date       : [Date of Submission]

// Description:
// This program uses two push buttons and an OLED display to control LEDs 
// and a buzzer connected to an ESP32 microcontroller.

// - Button 1 cycles through four LED modes:
//   1. Both OFF
//   2. Alternate Blink
//   3. Both ON
//   4. PWM Fade

// - Button 2 resets the system back to the OFF state.
// The current mode is displayed on the OLED screen in real time.

// Tools Used:
// - Wokwi (for circuit simulation)
// - Arduino IDE (for programming)
// --------------------------------------------------------------

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int button1Pin = 32;
const int button2Pin = 33;
const int led1Pin = 5;
const int led2Pin = 4;
const int buzzerPin = 15;

volatile bool button1Pressed = false;
volatile bool button2Pressed = false;

unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
const unsigned long debounceDelay = 150;

bool led1State = LOW;
bool led2State = LOW;

int mode = 0;  // 0=OFF, 1=Alternate Blink, 2=Both ON, 3=PWM Fade
unsigned long lastBlinkTime = 0;
int fadeValue = 0;
int fadeStep = 5;
unsigned long lastFadeTime = 0;
void updateDisplay(); 

void IRAM_ATTR handleButton1() {
  button1Pressed = true;
}

void IRAM_ATTR handleButton2() {
  button2Pressed = true;
}

void setup() {
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(button1Pin), handleButton1, FALLING);
  attachInterrupt(digitalPinToInterrupt(button2Pin), handleButton2, FALLING);

  // --- OLED setup ---
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Mode: Both OFF");
  display.display();
}

void loop() {
  unsigned long currentTime = millis();

  // --- Handle Button 1 (Mode Change) ---
  if (button1Pressed && (currentTime - lastDebounceTime1 > debounceDelay)) {
    button1Pressed = false;
    lastDebounceTime1 = currentTime;
    if (digitalRead(button1Pin) == LOW) {
      mode = (mode + 1) % 4;  // Cycle through modes
      updateDisplay();
    }
  }

  // --- Handle Button 2 (Reset to OFF) ---
  if (button2Pressed && (currentTime - lastDebounceTime2 > debounceDelay)) {
    button2Pressed = false;
    lastDebounceTime2 = currentTime;
    if (digitalRead(button2Pin) == LOW) {
      mode = 0;
      updateDisplay();
    }
  }

  // --- Handle each mode ---
  if (mode == 0) {  // Both OFF
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  else if (mode == 1) {  // Alternate blink
    if (currentTime - lastBlinkTime >= 500) {
      lastBlinkTime = currentTime;
      led1State = !led1State;
      led2State = !led2State;
      digitalWrite(led1Pin, led1State);
      digitalWrite(led2Pin, led2State);
      digitalWrite(buzzerPin, led1State);
    }
  }

  else if (mode == 2) {  // Both ON
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }

  else if (mode == 3) {  // PWM Fade (non-blocking)
    if (currentTime - lastFadeTime >= 15) {  // Adjust fade speed
      lastFadeTime = currentTime;
      fadeValue += fadeStep;
      if (fadeValue <= 0 || fadeValue >= 255) fadeStep = -fadeStep;

      // Simulate PWM brightness
      int brightnessDelay = map(fadeValue, 0, 255, 1, 15);
      digitalWrite(led1Pin, HIGH);
      digitalWrite(led2Pin, LOW);
      delayMicroseconds(brightnessDelay * 100);
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, HIGH);
      delayMicroseconds(brightnessDelay * 100);

      digitalWrite(buzzerPin, fadeValue % 2);
    }
  }
}

// --- OLED update function ---
void updateDisplay() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("Mode: ");
  if (mode == 0) display.println("Both OFF");
  else if (mode == 1) display.println("Alternate Blink");
  else if (mode == 2) display.println("Both ON");
  else if (mode == 3) display.println("PWM Fade");
  display.display();
}
