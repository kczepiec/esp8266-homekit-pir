# ESP8266 HomeKit Motion Sensor

This project implements a simple motion sensor using an Arduino and the Arduino HomeKit Server library. It connects to a HomeKit-compatible network and notifies HomeKit clients when motion is detected.

## Features

- Connects to Wi-Fi using provided credentials.
- Monitors a motion sensor connected to a specified D1 pin.
- Sends motion detection updates to HomeKit clients.
- Logs information about memory usage and connected HomeKit clients.

## Requirements

- Arduino IDE
- ESP8266 or ESP32 board (for Wi-Fi capability)
- Arduino HomeKit Server library
- Any necessary libraries for Wi-Fi connectivity
- A motion sensor (e.g., PIR sensor)