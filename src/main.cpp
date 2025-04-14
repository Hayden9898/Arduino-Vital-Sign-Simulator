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
int healthy = 7;
int danger = 6;
void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(healthy, OUTPUT);
  pinMode(danger, OUTPUT);
}

void loop()
{
  int potInput = analogRead(A0);
  int bpm = map(potInput, 0, 1023, 50, 150);
  
  int TMPinput = analogRead(A1);
  float tempC = (TMPinput / 358.0) * 10.0 + 30.0;
  
  //Print out BPM
  lcd.setCursor(0,0);
  lcd.print("Current BPM: ");
  lcd.setCursor(12,0);
  lcd.print("   ");
  lcd.setCursor(12,0);
  lcd.print(bpm);
  
  //Print out Temp in degress Celcius
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.setCursor(6,1);
  lcd.print("   ");
  lcd.setCursor(6,1);
  lcd.print(tempC);
  
  if(bpm < 90 && bpm > 50 && tempC > 36 && tempC < 37){
   	digitalWrite(healthy, HIGH); 
    digitalWrite(danger, LOW); 
  } else {
    digitalWrite(healthy, LOW); 
    digitalWrite(danger, HIGH);
  }
  delay(100);
  
}