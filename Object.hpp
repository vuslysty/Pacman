//
// Created by Vladyslav USLYSTYI on 2019-09-16.
//

#ifndef PACMAN_OBJECT_HPP
#define PACMAN_OBJECT_HPP


#include "Point.hpp"

class Object
{

protected:

	Point	pos;

public:

	Point &getPos();

	void	setPos(int x, int y);
	void	setPos(Point &p);
	void	incrementX();
	void	incrementY();
	void	decrementX();
	void	decrementY();
};


#endif //PACMAN_OBJECT_HPP
