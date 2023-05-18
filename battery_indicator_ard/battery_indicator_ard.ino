#include <LiquidCrystal.h>   // Include the LCD library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   // Initialize the LCD object with the pin numbers
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;
String batteryPercentage = "";
String prevBatteryPercentage = "";

void setup() {
  lcd.begin(16, 2);    // Initialize the LCD with 16 columns and 2 rows
  lcd.print("Laptop Battery:");    // Display initial message
  Serial.begin(9600);    // Initialize serial communication
}

void loop() {
  if (Serial.available() > 0) {
    batteryPercentage = Serial.readString();

    if (batteryPercentage != prevBatteryPercentage) {
      lcd.clear();
      lcd.print("Battery: ");
      lcd.print(batteryPercentage);
      lcd.print("%");
      prevBatteryPercentage = batteryPercentage;
    }
  }
}