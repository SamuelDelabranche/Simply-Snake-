#include "fruit.h"

#include <iostream>
#include <ctime>

using namespace std;


void Fruit::randomFruit(const int sW, const int sH) {
	srand(static_cast<unsigned>(time(nullptr)));

	this->m_x = rand() % (sW-1) +1;
	this->m_y = rand() % (sH-1) +1;

}

int Fruit::getPos(char pos) const {
	return (pos == 'x') ? this->m_x : this->m_y;
}

char Fruit::getCharacter() const {
	return this->m_character;
}