#include <Arduino.h>

class FourDigitLCD {

public:
FourDigitLCD();
  void init();
  void display(int number);
};
