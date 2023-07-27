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

void Snake::addMovement() {
	switch (m_dir){
		case 'z': m_y -= 1; break;
		case 's': m_y += 1; break;
		case 'q': m_x -= 1; break;
		case 'd': m_x += 1; break;
	}
}

void Snake::setPos(const char& newDir) {
	this->m_dir = newDir;
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