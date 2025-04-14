/*This project models Studio 1 Labs' smart fabric technology 
using embedded systems. A potentiometer simulates heart rate and a 
TMP36 sensor simulates body temperature. An Arduino reads these inputs,
processes the data, and displays the results on an LCD.

Two LEDs indicate health status based on real-time readings—green for 
normal, red for abnormal. This demonstrates howem bedded systems 
collect, process, and respond to biometric data, just like Studio 
1 Labs' intelligent hospital bedding.

Note: 
BPM is constrained to 50-150
Temperature is constrained to 30-40 degrees.
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// LED pins
const int healthyLED = 7;
const int dangerLED = 6;

// Sensor pins
const int bpmPin = A0;
const int tempPin = A1;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  pinMode(healthyLED, OUTPUT);
  pinMode(dangerLED, OUTPUT);
}

void loop() {
  // Read and map heart rate (potentiometer input)
  int potInput = analogRead(bpmPin);
  int bpm = map(potInput, 0, 1023, 50, 150);

  // Read and convert TMP36 temperature sensor input
  int tempInput = analogRead(tempPin);
  float tempC = (tempInput / 358.0) * 10.0 + 30.0;

  // Display BPM
  lcd.setCursor(0, 0);
  lcd.print("Current BPM: ");
  lcd.setCursor(12, 0);
  lcd.print("   "); // Clear old digits
  lcd.setCursor(12, 0);
  lcd.print(bpm);

  // Display Temperature
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.setCursor(6, 1);
  lcd.print("     "); // Clear old digits
  lcd.setCursor(6, 1);
  lcd.print(tempC);

  // Vital sign evaluation
  bool bpmOK = (bpm >= 50 && bpm <= 90);
  bool tempOK = (tempC >= 36.0 && tempC <= 37.0);

  if(bpmOK && tempOK){
    digitalWrite(healthyLED, HIGH);
    digitalWrite(dangerLED, LOW);
  }else{
    digitalWrite(healthyLED, LOW);
    digitalWrite(dangerLED, HIGH);
  }

  delay(100);
}