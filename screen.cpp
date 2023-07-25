#include "screen.h"
#include "fruit.h"
#include "snake.h"

#include <iostream>
#include <windows.h> 
using namespace std;


Screen::Screen(int w, int h) : m_width(w), m_height(h) {
	snake = new Snake;
	fruit = new Fruit;
	fruit->randomFruit(m_width, m_height);
	drawArena();
}

Screen::~Screen() {
	delete fruit;
	delete snake;
}

void Screen::updateScreen() const {
	drawArena();
}


void Screen::drawArena() const {
	Sleep(500); 
	system("cls");


	for (int i = 0; i < m_width; i++) {
		cout << m_borderCharacter;
	} // TOP border
	cout << endl;

	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			if (x == 0 || x == m_width - 1) {
				cout << m_borderCharacter;
			}
			else if (x == fruit->getPos('x') && y == fruit->getPos('y')){
				cout << fruit->getFruitCharacter();
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < m_width; i++) {
		cout << m_borderCharacter;
	} // BOTTOM border

	cout << endl;
	cout << "Fruit : X{" << fruit->getPos('x') << "} | Y{" << fruit->getPos('y') << "}" << endl;

}

