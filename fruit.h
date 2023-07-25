#pragma once
#ifndef FRUIT_H
#define FRUIT_H


class Fruit{
	protected:
		int m_x = 0;
		int m_y = 0;
		char m_character = 'F';

	public:
		void randomFruit(const int sW, const int sH);
		int getPos(char pos) const;
		char getFruitCharacter() const;
};

#endif