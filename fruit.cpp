#include "fruit.h"

#include <iostream>

using namespace std;


void Fruit::randomFruit(const int sW, const int sH) {
	srand(static_cast<unsigned>(time(nullptr)));

	this->m_x = rand() % sW;
	this->m_y = rand() % sH;

}

int Fruit::getPos(char pos) const {
	return (pos == 'x') ? this->m_x : this->m_y;
}

char Fruit::getCharacter() const {
	return this->m_character;
}