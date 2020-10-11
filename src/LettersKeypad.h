#ifndef LETTERSKEYPAD_H
#define LETTERSKEYPAD_H

#include <Keypad.h>

#define CAPSLOCK_OFF 0
#define CAPSLOCK_ON  1
#define NUMBER       2

#define _ROWS 4
#define _COLS 3

class LettersKeypad : public Keypad {
private:
	static const char map[_ROWS][_COLS];
	static const char letters[12][4];
	char oldKey, pressedKey, tempKey;
	byte mode, count;
	int interval;
	long ct;
	
public:
	LettersKeypad(byte *r, byte *c);
	char getRawLetter();
	char getLetter();
	byte getMode() {return mode;}
	void setUpdateTime(int dly = 1000) {interval = dly;}
};

#endif