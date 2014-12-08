fourDigitLCDDisplay
===================

Arduino library to use a 7 segment 4 digit LCD Display

This code can be used to display numbers on a 7x4 Display like this https://www.sparkfun.com/products/11407.
For the right pins see the following schema:

![Pins](pins.png)

This pins layout will fit the LCD above but it can be easily changed in the code.

To connect the digit pins you may want to use a resistor (e.g. 1k). It will work (for a short time) without but then it will burn out your segments.
