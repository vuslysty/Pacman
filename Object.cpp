//
// Created by Vladyslav USLYSTYI on 2019-09-16.
//

#include "Object.hpp"

const Point& Object::getPos() const
{
	return (pos);
}

void Object::setPos(int x, int y)
{
	pos.setXY(x, y);
}

void Object::setPos(Point &p)
{
	pos = p;
}

void Object::incrementY()
{
	pos.incrementY();
}

void Object::incrementX()
{
	pos.incrementX();
}

void Object::decrementX()
{
	pos.decrementX();
}

void Object::decrementY()
{
	pos.decrementY();
}

