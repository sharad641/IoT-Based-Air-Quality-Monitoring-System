/*   #include <LiquidCrystal.h>  // Header file for LCD 
#include <DHT.h>            // Library for DHT sensor 
// LCD Pins 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
// DHT Sensor Pins and Type 
#define DHTPIN 7       // Data pin connected to Arduino pin 7 
#define DHTTYPE DHT11  // DHT11 or DHT22 sensor 
DHT dht(DHTPIN, DHTTYPE); 
// Other components 
int buz = 8;                  // Buzzer connected to pin 8 
int led = 9;                  // LED connected to pin 9 
const int aqsensor = A0;      // MQ135 output connected to A0 
int threshold = 120;          // Threshold for air quality 
void setup() { 
  pinMode(buz, OUTPUT);       // Set buzzer as output 
  pinMode(led, OUTPUT);       // Set LED as output 
  pinMode(aqsensor, INPUT);   // Set MQ135 as input 
  Serial.begin(9600);         // Begin serial communication 
  lcd.begin(16, 2);           // Initialize 16x2 LCD 
  lcd.clear(); 
  dht.begin();                // Initialize DHT sensor 
} 
void loop() { 
  // Read air quality 
  int ppm = analogRead(aqsensor); 
  // Read temperature and humidity 
  float temp = dht.readTemperature(); 
  float hum = dht.readHumidity(); 
  // Print to Serial Monitor 
  Serial.print("Air Quality: "); 
  Serial.println(ppm); 
  Serial.print("Temperature: "); 
  Serial.print(temp); 
  Serial.println(" C"); 
  Serial.print("Humidity: "); 
  Serial.print(hum); 
  Serial.println(" %"); 
  // Display on LCD 
  lcd.clear(); // Clear the LCD before updating 
  // Line 1: Air Quality 
  lcd.setCursor(0, 0); 
  lcd.print("AQ: "); 
  lcd.print(ppm); 
  lcd.print(" ppm"); 
  // Line 2: Temperature and Humidity 
  lcd.setCursor(0, 1); 
  lcd.print("T:"); 
  lcd.print(temp, 1); // Print temperature with 1 decimal place 
  lcd.print("C H:"); 
  lcd.print(hum, 1); // Print humidity with 1 decimal place 
  lcd.print("%"); 
  // Air quality threshold check 
  if (ppm > threshold) { 
    tone(buz, 1000, 200);      // Activate buzzer 
    digitalWrite(led, HIGH);   // Turn on LED 
    Serial.println("AQ Level HIGH"); 
  } else { 
    digitalWrite(led, LOW);    // Turn off LED 
    digitalWrite(buz, LOW);    // Turn off buzzer 
    Serial.println("AQ Level Good"); 
  } 
  delay(2000); // Wait for 2 seconds before the next readin
}  */