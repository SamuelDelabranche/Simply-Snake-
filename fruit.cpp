#include "fruit.h"

#include <iostream>

using namespace std;


void Fruit::randomFruit(const int sW, const int sH) {
	srand(static_cast<unsigned>(time(nullptr)));

	m_x = rand() % sW;
	m_y = rand() % sH;

}

int Fruit::getPos(char pos) const {
	return (pos == 'x') ? m_x : m_y;
}

char Fruit::getFruitCharacter() const {
	return m_character;
}