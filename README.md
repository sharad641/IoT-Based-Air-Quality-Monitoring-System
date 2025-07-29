# 🌍 IoT-Based Air Quality Monitoring System

![Air Quality Monitor](images/output_display.jpg)

A cost-effective and scalable IoT system for real-time monitoring of air pollutants, temperature, and humidity using Arduino, MQ135, and DHT11. The system alerts users when pollution levels exceed safe thresholds, enabling better public awareness and health decisions.

---

## 📘 Table of Contents

- [🔍 Project Overview](#-project-overview)
- [🧠 Working Principle](#-working-principle)
- [🧰 Hardware Components](#-hardware-components)
- [💡 Software & Libraries](#-software--libraries)
- [🔌 Circuit Diagram](#-circuit-diagram)
- [📟 Output Display](#-output-display)
- [🚨 Alert System](#-alert-system)
- [🛠️ Setup Instructions](#-setup-instructions)
- [📄 Full Project Report](#-full-project-report)
- [📦 Future Enhancements](#-future-enhancements)
- [🧾 License](#-license)

---

## 🔍 Project Overview

Air pollution from vehicles and industries is a critical environmental and public health issue. This project introduces an **IoT-based air quality monitoring system** that uses affordable components to provide real-time environmental data.

### Key Features:

- Detects harmful gases: **CO₂**, **NOₓ**, **NH₃**
- Monitors **temperature** and **humidity**
- Displays live data on an **LCD screen**
- Buzzer & LED alerts when air quality is poor
- Built using low-cost components like **Arduino Uno**, **MQ135**, **DHT11**

---

## 🧠 Working Principle

1. **MQ135 Sensor** reads air pollutants in analog format.
2. **DHT11 Sensor** provides temperature and humidity.
3. **Arduino Uno** processes the data.
4. If gas concentration exceeds a **threshold (e.g., 120 PPM)**:
   - Buzzer activates
   - LED turns on
5. All values are displayed on a **16x2 LCD display**.

---

## 🧰 Hardware Components

| Component              | Quantity | Description                                    |
|------------------------|----------|------------------------------------------------|
| Arduino Uno            | 1        | Microcontroller board                          |
| MQ135 Gas Sensor       | 1        | Air quality sensor (CO₂, NOₓ, NH₃)             |
| DHT11 Sensor           | 1        | Temperature and humidity sensor                |
| 16x2 LCD Display       | 1        | Shows live data                                |
| Buzzer                 | 1        | Audio alert when air is unsafe                 |
| LED                    | 1        | Visual pollution alert                         |
| Resistors, Breadboard, Jumper wires | As needed | For connections and prototyping        |
| 5V Power Supply        | 1        | Arduino & component power                     |

---

## 💡 Software & Libraries

- [Arduino IDE](https://www.arduino.cc/en/software)
- Libraries used:
  - `LiquidCrystal.h`
  - `DHT.h`

📁 Arduino code: [`ArduinoCode/air_quality_monitor.ino`](ArduinoCode/air_quality_monitor.ino)

---

## 🔌 Circuit Diagram

Upload your circuit diagram here and name it `circuit_diagram.jpg`.

```text
images/circuit_diagram.jpg


📟 Output Display
When the system runs, the 16x2 LCD shows:

AQ: 110 ppm
T:28.6C H:48.2%

If air quality crosses 120 PPM:

A buzzer will sound.

A red LED lights up.

LCD continues updating.


🚨 Alert System
Air quality threshold: 120 PPM

If ppm > 120:

Buzzer sounds (tone(1000, 200))

LED turns on

If ppm <= 120:

Alerts are turned off

This ensures users are warned about unhealthy environmental conditions in real time.

📄 Full Project Report
📄 Download the complete report: Report/IOT_AirPollution_Project_Report.pdf

Includes:

Abstract

Literature Survey

Methodology

Implementation

Results & Testing

Arduino Source Code

Circuit & LCD Output Images

📦 Future Enhancements
Cloud data logging (e.g., Blynk, Thingspeak)

Mobile app integration (via WiFi/ESP8266)

Particulate Matter sensors (PM2.5/PM10)

GPS location tagging

Solar-powered units for remote areas

🧾 License
This project is open-source under the MIT License.

See LICENSE for details.

🤝 Acknowledgments
DHT Sensor Library - Adafruit

LiquidCrystal Library - Arduino

Faculty at Dept. of CS-ICB, DSATM Bangalore

“Breathe Clean, Live Green 🌱”


---

## ✅ What You Need to Upload

In your GitHub repo:
1. `README.md` → use the file above.
2. `ArduinoCode/air_quality_monitor.ino` → extracted from your report.
3. `Report/IOT_AirPollution_Project_Report.pdf` → your provided PDF.
4. `images/circuit_diagram.jpg` → circuit image (add your own).
5. `images/output_display.jpg` → LCD screen output image.
6. `LICENSE` → choose MIT (recommended).

---

Would you like me to generate the `.ino` file for you now based on the report’s code?
