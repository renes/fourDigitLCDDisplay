#include "FourDigitLCD.h"

FourDigitLCD lcd; 

void setup() {
  lcd.init();
}

void loop() {
  lcd.display(42);
}

