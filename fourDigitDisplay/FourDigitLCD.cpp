#include <Arduino.h>

#include "FourDigitLCD.h"

// Array of all pins we use so we can easy set them to low for cleaning
int pins[] = { 
  2,3,4,5,6,7,8,9,10,11,12,13 };

// matrix one entry for each number 0-9
int numbers[][7] = {
  {
    HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW               }
  ,  {
    LOW, HIGH, HIGH, LOW, LOW, LOW, LOW               }
  ,{ 
    HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH               }
  , {
    HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH               }
  , {
    LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH               }
  ,{
    HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH               } 
  ,{
    HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH               }
  ,{
    HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW               }
  , {
    HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH               }
  ,{
    HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH               }
};

// our pins used for digts
int DIGIT_1 = 13;
int DIGIT_2 = 10;
int DIGIT_3 = 9;
int DIGIT_4 = 7;

// pins used for segments
int A = 12;
int B = 8;
int C = 5;
int D = 3;
int E = 2;
int F = 11;
int G = 6;

// we want our number on the right side of the display, if you want to change it to the left you have to change this array
int digits[] = { 
  DIGIT_4, DIGIT_3, DIGIT_2, DIGIT_1 };

// used to map the pins to the numbers array above
int mapping[] = { 
  A, B, C, D, E, F, G };

FourDigitLCD::FourDigitLCD() {

}

void FourDigitLCD::init() {

}

void clear() {
  for (int i = 0; i <= sizeof(pins); i = i + 1) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
}

// prints the number on the given pin
void printNumber(int digit, int number) {

  // Set DIGIT pins HIGH, expect the one we need right now
  for (int i = 0; i < 4; i = i + 1) {
    if (digit == i) {
      digitalWrite(digits[i], LOW);
    } 
    else {
      digitalWrite(digits[i], HIGH);
    }
  } 

  // Set the segment pins
  for (int i = 0; i < 7; i = i + 1) {
    digitalWrite(mapping[i], numbers[number][i]);
  } 
}

void FourDigitLCD::display(int number) {
  clear();
  char b[5]; 
  String str;
  str=String(number);

  int length =  str.length();
  str.toCharArray(b,5);

  for (int i = 0; i < length; i++) {
    int digit = length -i -1;
    int currentDigit;
    currentDigit=b[i]-'0';
    printNumber(digit, currentDigit);
    delay(2);
  } 

}










