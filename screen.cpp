#include "screen.h"
#include "fruit.h"
#include "snake.h"

#include <iostream>
#include <windows.h> 
#include <string>
using namespace std;


Screen::Screen(int w, int h) : m_width(w), m_height(h) {
	snake = new Snake;
	fruit = new Fruit;
	fruit->randomFruit(m_width, m_height);
	snake->setOriginalPos((m_width+1) / 2, m_height / 2);
	drawArena();
}

Screen::~Screen() {
	delete fruit;
	delete snake;
}

bool Screen::logic() const{
	if (*snake == *fruit) {
		fruit->randomFruit(m_width, m_height);
		snake->incrementNbTails();
	}

	return (snake->getPos('x') <= 0 || snake->getPos('x') >= this->m_width || snake->getPos('y') <= -1 || snake->getPos('y') >= this->m_height);

}

void Screen::updateScreen() const {
	drawArena();
}

void Screen::setDir(const int &newDir) {
	switch (newDir)
	{
		case 1:
			this->m_dir = UP;
			snake->addMovement('y', false);
			break;
		case 2:
			this->m_dir = DOWN;
			snake->addMovement('y', true);
			break;
		case 3:
			this->m_dir = LEFT;
			snake->addMovement('x', false);
			break;
		case 4:
			this->m_dir = RIGHT;
			snake->addMovement('x', true);
			break;
		default:
			break;
	
	}
}

void Screen::changeSnakeMovement() {
	switch (m_dir)
	{
	case UP:
		break;
	case DOWN:
		break;
	case RIGHT:
		break;
	case LEFT:
		break;
	default:
		break;
	}
}

void Screen::drawArena() const {
	Sleep(30);
	system("cls");


	for (int i = 0; i < m_width+2; i++) {
		cout << m_borderCharacter;
	} // TOP border
	cout << endl;

	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width+2; x++) {
			if (x == 0 || x == m_width + 1) {
				cout << m_borderCharacter;
			}
			else if (x == snake->getPos('x') && y == snake->getPos('y')) { cout << snake->getCharacter(); }
			else if (x == fruit->getPos('x') && y == fruit->getPos('y')){ cout << fruit->getCharacter(); }
			else { cout << " "; }
			for (int i = 0; i < snake->getNbTails(); i++) {

			}
		}
		cout << endl;
	}

	for (int i = 0; i < m_width+2; i++) {
		cout << m_borderCharacter;
	} // BOTTOM border

	cout << endl;
	cout << "Fruit : X{" << fruit->getPos('x') << "} | Y{" << fruit->getPos('y') << "}" << endl;
	cout << "Snake : X{" << snake->getPos('x') << "} | Y{" << snake->getPos('y') << "}" << endl;
	cout << "count of tails : " << snake->getNbTails() << endl;


}



