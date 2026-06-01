i# Arduino Bluetooth RC Car 🚗

A Bluetooth-controlled RC car project powered by an Arduino microcontroller. This project features wireless mobile control and custom police-style alternating strobe lights.

## 🚀 Features
* **Wireless Control:** Complete directional control via a Bluetooth smartphone app.
* **Strobe Lights:** Integrated alternating Red and Blue police-style strobe light effect.
* **Hardware Control:** Efficient motor switching using an L298N motor driver.

## 🛠 Hardware Required
* Arduino UNO / Nano
* L298N Motor Driver Module
* HC-05 Bluetooth Module
* DC Motors and Chassis
* LEDs (Red & Blue for Strobe)
* Jumper Wires & Power Supply (Battery)

![RC Car Circuit Diagram](Circuit Diagram.png.jpg)


## 💻 How to use
1. Upload the provided `.ino` file to the Arduino using the Arduino IDE. (Note: Disconnect the HC-05 TX/RX pins while uploading code).
2. Connect the hardware according to the pin definitions in the code.
3. Pair the HC-05 module with your smartphone's Bluetooth settings (default PIN: 0000 or 1234).
4. Use a standard Arduino Bluetooth Controller app to drive the car and toggle the strobe lights!

---
*Created by Sanjay Sharma*
