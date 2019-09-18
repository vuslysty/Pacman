//
// Created by Vladyslav USLYSTYI on 2019-09-18.
//

#include "Cell.hpp"

int Cell::indexCounter = 0;

Cell::Cell(int x, int y)
{
	pos = Point(x, y);
	index = indexCounter++;
}

int Cell::getIndex() const
{
	return index;
}

int Cell::getIndexCounter() const
{
	return indexCounter;
}

const Point &Cell::getPos() const
{
	return pos;
}

Cell::Cell(Cell const &src)
{
	*this = src;
}

Cell& Cell::operator=(Cell const &rhs)
{
	if (this != &rhs)
	{
		this->pos = rhs.pos;
		this->index = rhs.index;
	}
	return *this;
}
