#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include "fruit.h"
#include "snake.h"

class Screen{
	private:
		Snake* snake;
		Fruit* fruit;
		int m_width, m_height;

		char m_borderCharacter = '#';

		enum direction { UP, DOWN, RIGHT, LEFT };
		direction m_dir;
		void drawArena() const;

	public:
		Screen(int w = 40, int h = 20);
		~Screen();
		void updateScreen() const;
		void setDir(const int& newDir);
		void changeSnakeMovement();

		bool logic() const;
};


#endif
