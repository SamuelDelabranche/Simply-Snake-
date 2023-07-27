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
				case 'z': Arena.setDir('z'); break;
				case 's': Arena.setDir('s'); break;
				case 'q': Arena.setDir('q'); break;
				case 'd': Arena.setDir('d'); break;
				case 'x': gameOver = true; break;
			}
		}


	}

	return 0;
}
