#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,2,3,4,5);

void setup() {
  lcd.begin(16,2);
}

void loop() {
  lcd.setCursor(0,1);
  lcd.print("Hello World!");
  delay(1000);
  lcd.clear();
}
