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

void Screen::changeTailsPos() {
	m_prevPosX = m_posTailsX[0];
	m_prevPosY = m_posTailsY[0];

	m_posTailsX[0] = snake->getPos('x');
	m_posTailsY[0] = snake->getPos('y');

	for (int i = 1; i < snake->getTails(); i++) {
		m_tempPrevPosX = m_posTailsX[i];
		m_tempPrevPosY = m_posTailsY[i];

		m_posTailsX[i] = m_prevPosX;
		m_posTailsY[i] = m_prevPosY;

		m_prevPosX = m_tempPrevPosX;
		m_prevPosY = m_tempPrevPosY;

	}

}

bool Screen::logic(){


	if (*snake == *fruit) {
		fruit->randomFruit(m_width, m_height);
		snake->incrementTails();
	}
	bool cond1X = (snake->getPos('x') <= 0 );
	bool cond2X = (snake->getPos('x') >= this->m_width);
	
	bool cond1Y = (snake->getPos('y') <= -1);
	bool cond2Y = (snake->getPos('y') >= this->m_height);

	bool condTails = false;
	for (int i = 1; i < snake->getTails(); i++) {
		if (m_posTailsX[i] == snake->getPos('x') && m_posTailsY[i] == snake->getPos('y')) { 
			condTails = true; 
			break; }
	}


	return (cond1X || cond2X || cond1Y || cond2Y || condTails);

}

void Screen::updateScreen(){
	drawArena();
}

void Screen::setDir(const int &newDir) {
	switch (newDir)
	{
		case 'z':
			snake->setPos('z');
			break;
		case 's':
			snake->setPos('s');
			break;
		case 'q':
			snake->setPos('q');
			break;
		case 'd':
			snake->setPos('d');
			break;
	
	}
	snake->addMovement();
	changeTailsPos();

}

void Screen::drawArena() const {
	Sleep(30);
	system("cls");



	for (int i = 0; i < m_width+1; i++) {
		cout << m_borderCharacter;
	} // TOP border
	cout << endl;

	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width+1; x++) {
			if (x == 0 || x == m_width) {
				cout << m_borderCharacter;
			}
			else if (x == snake->getPos('x') && y == snake->getPos('y')) { cout << snake->getCharacter(); }
			else if (x == fruit->getPos('x') && y == fruit->getPos('y')){ cout << fruit->getCharacter(); }
			else{ 
				bool check = false;

				for (int i = 1; i < snake->getTails(); i++) {
					if (m_posTailsX[i] == x && m_posTailsY[i] == y) { cout << snake->getTailsCharacter(); check = true; }
				
				}
				if (!check) { cout << " ";}
				
			}

		}
		cout << endl;
	}

	for (int i = 0; i < m_width+1; i++) {
		cout << m_borderCharacter;
	} // BOTTOM border

	cout << endl;
	cout << "\t\tScore : " << (snake->getTails()-1)*10 << endl;

}



