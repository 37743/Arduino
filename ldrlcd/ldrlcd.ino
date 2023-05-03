#include <LiquidCrystal.h>
const int LDRpin = A0;
LiquidCrystal lcd(12,11,2,3,4,5);

void setup() {
  pinMode(LDRpin, INPUT);  
  lcd.begin(16,2);
}

void loop() {
  int ldr = analogRead(LDRpin);
  lcd.setCursor(0,1);
  lcd.print(ldr);
  delay(3000);
  lcd.clear();
}
