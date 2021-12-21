#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void initLCD() {
  lcd.begin(16, 2);
}

void clearLCDLine(int line) {
  lcd.setCursor(0, line);
  lcd.print("                ");
}
