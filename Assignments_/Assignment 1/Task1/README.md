# Assignment 1 — ESP32 LED Modes and Button Control

## 👩‍💻 Student Info
**Name:** Ayesha Iftikhar  
**Reg. No.:** 23-NTU-CS-1021  
**Section:** BSCS 5th (A)

---

## 🧠 Project Overview
This project demonstrates LED control on an ESP32 using push buttons and an OLED display.  
- **Button 1:** Cycles through LED modes  
  1. Both OFF  
  2. Alternate Blink  
  3. Both ON  
  4. PWM Fade  
- **Button 2:** Resets LEDs to OFF state.  

---

## 🔗 Wokwi Simulation
[Click here to view the simulation on Wokwi](
https://wokwi.com/projects/445722481831695361
)

---

## 📍 Pin Map
| Component        | ESP32 Pin | Notes                                    |
| ---------------- | --------- | ---------------------------------------- |
| Button 1 (Mode)  | GPIO 32   | Input, uses `INPUT_PULLUP` and interrupt |
| Button 2 (Reset) | GPIO 33   | Input, uses `INPUT_PULLUP` and interrupt |
| LED 1            | GPIO 5    | Output                                   |
| LED 2            | GPIO 4    | Output                                   |
| Buzzer           | GPIO 15   | Output                                   |
| OLED SDA         | GPIO 21   | I2C SDA (Wire library default)           |
| OLED SCL         | GPIO 22   | I2C SCL (Wire library default)           |

---

## ⚙️ Tools Used
- **Arduino IDE** – for programming  
- **Wokwi** – for simulation  
- **GitHub** – for version control
