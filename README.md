# 🌍 IoT-Based Air Quality Monitoring System

![Air Quality Monitor](https://github.com/sharad641/IoT-Based-Air-Quality-Monitoring-System/blob/main/images/circuit_diagram.jpg)

A low-cost, scalable IoT system for real-time monitoring of air pollutants, temperature, and humidity using Arduino, MQ135, and DHT11. Designed to raise environmental awareness and provide alerts when pollution exceeds safe limits.

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

Air pollution poses major health and environmental risks. This project presents a smart, cost-effective solution using IoT to continuously monitor:

- Harmful gases like **CO₂**, **NOₓ**, **NH₃** (via MQ135)
- **Temperature** and **humidity** (via DHT11)
- **Visual display** on a 16x2 LCD
- **Buzzer + LED alerts** when air is unsafe

The system helps users make informed decisions in real time to avoid polluted environments.

---

## 🧠 Working Principle

1. **MQ135** detects air pollution (PPM).
2. **DHT11** captures temperature & humidity.
3. **Arduino Uno** processes and displays data on LCD.
4. If gas exceeds a set threshold (e.g., 120 PPM):
   - **Buzzer** and **LED** alert users.
5. Data updates every 2 seconds.

---

## 🧰 Hardware Components

| Component            | Quantity | Function                                           |
|----------------------|----------|----------------------------------------------------|
| Arduino Uno          | 1        | Central microcontroller                            |
| MQ135 Sensor         | 1        | Air quality (CO₂, NOₓ, NH₃) sensor                |
| DHT11 Sensor         | 1        | Temperature and humidity sensor                    |
| 16x2 LCD Display     | 1        | Real-time environmental display                    |
| Buzzer               | 1        | Alerts when air quality is poor                    |
| LED                  | 1        | Visual indication of unsafe air                    |
| Breadboard + Wires   | As needed| Prototyping and circuit connections                |
| 5V Power Supply      | 1        | Powering Arduino and components                    |

---

## 💡 Software & Libraries

- [Arduino IDE](https://www.arduino.cc/en/software)
- Libraries used:
  - `LiquidCrystal.h`
  - `DHT.h`

📁 **Arduino Sketch**: `ArduinoCode/air_quality_monitor.ino`

```cpp
#include <LiquidCrystal.h>
#include <DHT.h>

// LCD Pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// DHT Sensor
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Buzzer & LED
int buz = 8;
int led = 9;

// MQ135 Sensor
const int aqsensor = A0;
int threshold = 120;

void setup() {
  pinMode(buz, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(aqsensor, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  dht.begin();
}

void loop() {
  int ppm = analogRead(aqsensor);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.print("Air Quality: "); Serial.println(ppm);
  Serial.print("Temperature: "); Serial.print(temp); Serial.println(" C");
  Serial.print("Humidity: "); Serial.print(hum); Serial.println(" %");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AQ: "); lcd.print(ppm); lcd.print(" ppm");

  lcd.setCursor(0, 1);
  lcd.print("T:"); lcd.print(temp, 1); lcd.print("C ");
  lcd.print("H:"); lcd.print(hum, 1); lcd.print("%");

  if (ppm > threshold) {
    tone(buz, 1000, 200);
    digitalWrite(led, HIGH);
    Serial.println("AQ Level HIGH");
  } else {
    digitalWrite(led, LOW);
    digitalWrite(buz, LOW);
    Serial.println("AQ Level Good");
  }

  delay(2000); // Wait 2 seconds
}

🔌 Circuit Diagram
🖼️ Circuit diagram image embedded from your GitHub:

📟 Output Display
When running, the LCD displays:
AQ: 110 ppm
T:28.6C H:48.2%

If air quality is poor (> 120 ppm):

🔊 Buzzer activates

🔴 LED turns on


🚨 Alert System
| Threshold (PPM) | Status   | Buzzer | LED |
| --------------- | -------- | ------ | --- |
| ≤ 120           | Good Air | Off    | Off |
| > 120           | Poor Air | On     | On  |
Threshold is customizable in code (threshold = 120).
🛠️ Setup Instructions
Assemble components as per the circuit.

Install DHT & LiquidCrystal libraries in Arduino IDE.

Upload the .ino code to your Arduino Uno.

Open Serial Monitor (9600 baud) to view raw readings.

Watch live updates on LCD and alerts when needed.

📄 Full Project Report
📑 Full detailed PDF report available here:

Report/IOT_AirPollution_Project_Report.pdf

Includes:

Abstract & Objectives

Literature Review

Proposed Method

Circuit Diagram & Code

Test Results & Graphs

Appendix: Source Code
📦 Future Enhancements
📡 Send data to cloud platforms (ThingSpeak, Firebase)

📱 Mobile app/dashboard integration

🔍 Add PM2.5 / PM10 sensors

📍 GPS for pollution mapping

☀️ Solar power for remote deployment

🧾 License
This project is licensed under the MIT License.
See LICENSE for more information.

🤝 Acknowledgments
Developed under Dept. of CS-ICB, DSATM Bangalore

Libraries: Adafruit DHT, Arduino LCD
"Breathe Smart. Live Green. Monitor Air Quality in Real Time."


---

### ✅ What's Left for You

1. Create these folders in your repo:
   - `ArduinoCode/air_quality_monitor.ino` (already done)
   - `Report/IOT_AirPollution_Project_Report.pdf` (add your report)
2. Ensure image links match GitHub repo (yours already does ✅).
3. Add `LICENSE` file (`MIT` is fine).
4. Copy the above `README.md` into your GitHub repository root.

Let me know if you'd like a downloadable `.ino` or `.md` file, or help creating a license.

