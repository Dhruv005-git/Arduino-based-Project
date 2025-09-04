# Smartphone-Controlled Smart Lighting System

## Overview

This project implements a **smartphone-controlled lighting system** using Arduino and Bluetooth. Users can control individual room lights or all lights remotely via an Android app. It demonstrates practical IoT concepts for everyday convenience in home automation.

---

## Features

* Control lights in **living room, bedroom, and dining room** individually.
* **Turn all lights ON/OFF** with a single command.
* Real-time feedback via Bluetooth messages to the phone.

---

## Components

**Hardware**

* Arduino UNO R3
* HC-05 Bluetooth Module
* 3 x LEDs with 220Ω resistors
* Breadboard & Jumper Wires
* Android phone with Bluetooth

**Software**

* Arduino IDE
* Arduino Bluetooth Controller App

---

## Folder Structure

```
code/               → Arduino source code (.ino)
photos/             → Project photos
report/             → Original project report (PDF)
README.md           → This file
```

---

## Setup Instructions

1. Connect LEDs to Arduino pins:

   * Living Room → Pin 5
   * Bedroom → Pin 6
   * Dining Room → Pin 7
2. Connect HC-05 Bluetooth module to Arduino:

   * RX → Pin 0, TX → Pin 1
3. Open `SmartLighting.ino` in Arduino IDE, upload to Arduino.
4. Open the Bluetooth Controller App on your phone.
5. Send commands to control individual or all lights:

| Command | Action          |
| ------- | --------------- |
| 4       | Living Room ON  |
| 1       | Living Room OFF |
| 5       | Bedroom ON      |
| 2       | Bedroom OFF     |
| 6       | Dining Room ON  |
| 3       | Dining Room OFF |
| 9       | All Lights ON   |
| 0       | All Lights OFF  |

---

## Photos

* `photos/running_project.jpg` → Project running
* `photos/team_working.jpg` → Team working on project

---

## Summary

This project provided hands-on experience with **Arduino programming**, **Bluetooth communication**, and **IoT integration** for a home lighting system. It is a solid foundation for future smart home automation projects.

---

## License

This project is licensed under the **MIT License**.
