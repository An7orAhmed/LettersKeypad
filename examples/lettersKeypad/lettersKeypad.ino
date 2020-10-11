#include <LettersKeypad.h>

byte col[] = {8, 7, 6};
byte row[] = {12, 11, 10, 9};

LettersKeypad keypad(row, col);

void setup() {
  Serial.begin(9600);
  keypad.setUpdateTime(2000);
}

void loop() {
  char k = keypad.getLetter();
  if(k) Serial.println(k);
}
