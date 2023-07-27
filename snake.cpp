#include "snake.h"

void Snake::setOriginalPos(const int &x, const int &y) {
	m_x = x;
	m_y = y;
}

int Snake::getPos(const char &pos) const {
	return (pos == 'x') ? this->m_x : this->m_y;
}

char Snake::getCharacter() const {
	return this->m_character;
}

char Snake::getTailsCharacter() const {
	return this->m_tailsCharacter;
}

void Snake::addMovement(const char& axis,const bool& sign) {
	if (axis == 'x') {
		if (sign == true) { this->m_x += 1; }
		else { this->m_x -= 1; }
	}
	else {
		if (sign == true) { this->m_y += 1; }
		else { this->m_y -= 1; }
	}
}

bool Snake::operator==(const Fruit& fruit) const {
	return (this->m_y == fruit.getPos('y') && this->m_x == fruit.getPos('x'));

}


void Snake::incrementTails() {
	++this->nbTails;
}

int Snake::getTails() const {
	return this->nbTails;
}