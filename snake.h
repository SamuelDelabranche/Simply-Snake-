#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "fruit.h"

class Snake : private Fruit{
	private:
		char m_character = 'O';
		int m_nbTails;
		int m_x;
		int m_y;

	public:
		void setpos(int x, int y);
};

#endif