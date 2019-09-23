//
// Created by Vladyslav USLYSTYI on 2019-09-18.
//

#include "Point.hpp"

Point::Point() : x(0), y(0)
{}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point::Point(Point const &src)
{
	*this = src;
}

Point& Point::operator=(Point const &rhs)
{
	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
	}
	return *this;
}

bool Point::operator==(Point const &rhs) const
{
	return (this->x == rhs.x && this->y == rhs.y);
}

bool Point::operator<(Point const &rhs) const
{
	if (this->y < rhs.y)
		return true;
	else if (this->y > rhs.y)
		return false;
	else
		return this->x < rhs.x;
}

const int Point::getX() const
{
	return x;
}

const int Point::getY() const
{
	return y;
}

void Point::setXY(int newX, int newY)
{
	*this = Point(newX, newY);
}

void Point::incrementX()
{
	this->x++;
}

void Point::incrementY()
{
	this->y++;
}

void Point::decrementX()
{
	this->x--;
}

void Point::decrementY()
{
	this->y--;
}

Point Point::tmpIncrementX() const
{
	Point	tmp = *this;

	tmp.incrementX();
	return tmp;
}

Point Point::tmpIncrementY() const
{
	Point	tmp = *this;

	tmp.incrementY();
	return tmp;
}

Point Point::tmpDecrementX() const
{
	Point	tmp = *this;

	tmp.decrementX();
	return tmp;
}

Point Point::tmpDecrementY() const
{
	Point	tmp = *this;

	tmp.decrementY();
	return tmp;
}

std::ostream	&operator<<(std::ostream &o, Point const &rhs)
{
	o << "[" << rhs.getY() << ":" << rhs.getX() << "]";
	return o;
}