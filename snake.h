#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "fruit.h"

class Snake : public Fruit{
	private:
		char m_character = 'X';
		char m_tailsCharacter = 'x';
		int m_x, m_y, nbTails = 1;

	public:
		void setOriginalPos(const int &x, const int &y);
		void addMovement(const char &axis, const bool &sign); // true = + | false = -
		int getPos(const char &pos) const;
		char getCharacter() const;
		char getTailsCharacter() const;

		void incrementTails();
		int getTails() const;

		bool operator==(const Fruit& fruit) const;
};

#endif