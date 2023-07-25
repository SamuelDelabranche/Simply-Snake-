#include "screen.h"

#include <iostream>
#include <iomanip>
#include <conio.h> 


int main() {
	Screen Arena;
	bool gameOver = false;

	while (!gameOver) {
		Arena.updateScreen();
		if (_kbhit()) {
			switch (_getch())
			{
				case 'x':
					gameOver = true;
					break;
			}
		}

	}

	return 0;
}
