#include "LettersKeypad.h"

static const char LettersKeypad::map[_ROWS][_COLS] = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
	{'*', '0', '#'},
};

static const char LettersKeypad::letters[12][4] = {
	{'.', ',', '=', ';'},
	{'a', 'b', 'c', NO_KEY},
	{'d', 'e', 'f', NO_KEY},
	{'g', 'h', 'i', NO_KEY},
	{'j', 'k', 'l', NO_KEY},
	{'m', 'n', 'o', NO_KEY},
	{'p', 'q', 'r', 's'},
	{'t', 'u', 'v', NO_KEY},
	{'w', 'x', 'y', 'z'},
	{'*', NO_KEY, NO_KEY, NO_KEY},
	{' ', NO_KEY, NO_KEY, NO_KEY},
	{'#', NO_KEY, NO_KEY, NO_KEY}
};

LettersKeypad::LettersKeypad(byte *r, byte *c) : Keypad(makeKeymap(map), r, c, _ROWS, _COLS) {
	setHoldTime(20);
	setUpdateTime(500);
}

char LettersKeypad::getRawLetter() {
	char letter, row;
	char key = getKey();
	
	if(key != NO_KEY) {
		if(key == '#') {
			mode++;
			if(mode > 2) mode = 0;
		}
		
		if(key >= '0' && key <= '9') {
			if(mode == NUMBER) return key;
			else {
				if(key == '0') row = 10;
				else row = key - 49;
				
				if(key == oldKey) {
					count++;
					if(count == 4 || letters[row][count] == NO_KEY) count = 0;
					letter = letters[row][count];
				}
				else {
					count = 0;
					letter = letters[row][count];
				}
				oldKey = key;
				if(mode == CAPSLOCK_ON) letter -= 32;
				
				return letter;
			}
		}
		else if(key == '*' || key == '#') return key;
	}
	return NO_KEY;
}

char LettersKeypad::getLetter() {
	char k = getRawLetter();
	if(k) {
		pressedKey = k;
		ct = millis();
	}
	if(millis() - ct >= interval && pressedKey != NO_KEY) {
		count = 0;
		oldKey = NO_KEY;
		tempKey = pressedKey;
		pressedKey = NO_KEY;
		return tempKey;
	}
	return NO_KEY;
}
