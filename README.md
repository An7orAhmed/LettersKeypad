# LettersKeypad
 A simple arduino alphanumeric (A-Z,a-z,0-9) 4x3 Matrix keypad.
 
dependency: <br>
Arduino Keypad: https://github.com/Chris--A/Keypad
 
1. initialize keypad:
---------------------
byte col[] = {8, 7, 6};<br>
byte row[] = {12, 11, 10, 9};<br>

LettersKeypad keypad(row, col);<br>

2. Set key release interval:
---------------------
keypad.setUpdateTime(2000);  // key will be print after 2sec
