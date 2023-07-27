#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>
#include "fruit.h"
#include "snake.h"

class Screen{
	private:
		Snake* snake;
		Fruit* fruit;
		int m_width, m_height;
		int m_posTailsX[100], m_posTailsY[100];
		int m_prevPosX = 0, m_prevPosY = 0, m_tempPrevPosX = 0, m_tempPrevPosY = 0;

		char m_borderCharacter = '#';

		int m_dir;
		void drawArena() const;

	public:
		Screen(int w = 40, int h = 20);
		~Screen();
		void updateScreen();
		void setDir(const int& newDir);
		bool logic();
		void changeTailsPos();
};


#endif
