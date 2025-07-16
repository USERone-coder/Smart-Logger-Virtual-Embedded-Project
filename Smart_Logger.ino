#include <LiquidCrystal.h>

const int voltagePin = A0;
const int currentPin = A1;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int rawVoltage = analogRead(voltagePin);
  int rawCurrent = analogRead(currentPin);

  float voltage = (rawVoltage * 5.0) / 1023.0 * 100;
  float current = (rawCurrent * 5.0) / 1023.0 * 10;

  lcd.setCursor(0, 0);
  lcd.print("V: ");
  lcd.print(voltage, 1);

  lcd.setCursor(0, 1);
  lcd.print("I: ");
  lcd.print(current, 1);

  if (voltage > 250 || current > 5) {
    lcd.setCursor(8, 0);
    lcd.print("FAULT!");
  } else {
    lcd.setCursor(8, 0);
    lcd.print("      ");
  }

  delay(1000);
}
