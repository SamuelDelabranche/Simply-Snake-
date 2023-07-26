#include "screen.h"

#include <iostream>
#include <iomanip>
#include <conio.h> 


int main() {
	Screen Arena;
	bool gameOver = false;

	while (!gameOver) {
		Arena.updateScreen();
		gameOver = Arena.logic();
		if (_kbhit()) {
			switch (_getch())
			{
				case 'z':
					Arena.setDir(1);
					break;
				case 's':
					Arena.setDir(2);
					break;
				case 'q':
					Arena.setDir(3);
					break;
				case 'd':
					Arena.setDir(4);
					break;
				case 'x':
					gameOver = true;
					break;
				default:
					break;
			}
		}


	}

	return 0;
}
