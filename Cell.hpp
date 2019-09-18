//
// Created by Vladyslav USLYSTYI on 2019-09-18.
//

#ifndef PACMAN_CELL_HPP
#define PACMAN_CELL_HPP


#include "Point.hpp"

class Cell
{
	Point	pos;
	int		index;
	int		dist;

	static int	indexCounter;

public:

	Cell() = default;
	Cell(int x, int y);
	Cell(Cell const &src);
	Cell	&operator=(Cell const &rhs);

	int			getIndex() const;

	int			getIndexCounter() const;

	const Point	&getPos() const;
};


#endif //PACMAN_CELL_HPP
