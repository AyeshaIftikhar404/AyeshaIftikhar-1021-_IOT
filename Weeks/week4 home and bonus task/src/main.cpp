//Ayesha Iftikhar
// 23-ntu-cs-1021
//section cs 5th A

//=================Hometask====================

//Display your name and ID using Adafruit_GFX text functions.
//-Draw a box around the text using drawRect()

// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>

// // ---- OLED setup ----
// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64
// #define OLED_ADDR 0x3C

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// void setup() {
//   Wire.begin(21, 22); // ESP32 default I2C pins (SDA=21, SCL=22)

//   if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
//     for (;;); // Stop if OLED not found
//   }

//   display.clearDisplay();

//   // --- Display name and ID ---
//   display.setTextSize(1);                // Small text
//   display.setTextColor(SSD1306_WHITE);
//   display.setCursor(25, 20);             // X, Y position
//   display.println("Ayesha Iftikhar");

//   display.setTextSize(1);
//   display.setCursor(40, 35);
//   display.println("ID: 1021");

//   // --- Draw box around text ---
//   // drawRect(x, y, width, height, color)
//   display.drawRect(10, 10, 108, 45, SSD1306_WHITE);

//   display.display(); // Show all on OLED
// }

// void loop() {
//   // Nothing here; static display
// }



// ===================Bonus Task========================

// Display your favorites Logo, Avatar, Emoji

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ❤ Heart Emoji (16x16)
const unsigned char heartEmoji[] PROGMEM = {
  0b00001100, 0b00110000,
  0b00011110, 0b01111000,
  0b00111111, 0b11111100,
  0b01111111, 0b11111110,
  0b01111111, 0b11111110,
  0b01111111, 0b11111110,
  0b00111111, 0b11111100,
  0b00011111, 0b11111000,
  0b00001111, 0b11110000,
  0b00000111, 0b11100000,
  0b00000011, 0b11000000,
  0b00000001, 0b10000000,
  0b00000000, 0b00000000,
  0b00000000, 0b00000000,
  0b00000000, 0b00000000,
  0b00000000, 0b00000000
};

// 🙂 Smiley Emoji (16x16)
const unsigned char smileyEmoji[] PROGMEM = {
  0b00000011, 0b11000000,
  0b00001111, 0b11110000,
  0b00011100, 0b00111000,
  0b00110000, 0b00001100,
  0b01100011, 0b11000110,
  0b01100111, 0b11100110,
  0b11000110, 0b01100011,
  0b11000110, 0b01100011,
  0b11000000, 0b00000011,
  0b11000000, 0b00000011,
  0b01100011, 0b11000110,
  0b01110000, 0b00001110,
  0b00111100, 0b00111100,
  0b00011111, 0b11111000,
  0b00000111, 0b11100000,
  0b00000000, 0b00000000
};

void setup() {
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    for (;;);
  }

  display.clearDisplay();

  // Draw multiple emojis on screen
  display.drawBitmap(20, 20, heartEmoji, 16, 16, SSD1306_WHITE);
  display.drawBitmap(60, 20, smileyEmoji, 16, 16, SSD1306_WHITE);
  display.drawBitmap(100, 20, heartEmoji, 16, 16, SSD1306_WHITE);

  display.display();
}

void loop() {
  // Nothing in loop
}