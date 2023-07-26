#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "fruit.h"

class Snake : public Fruit{
	private:
		char m_character = 'O';
		int m_nbTails = 0;
		int m_x = 0;
		int m_y = 0;

	public:
		void setOriginalPos(const int &x, const int &y);
		void addMovement(const char &axis, const bool &sign); // true = + | false = -
		int getPos(const char &pos) const;
		char getCharacter() const;
		void incrementNbTails();
		int getNbTails() const;

		bool operator==(const Fruit& fruit) const;
};

#endif