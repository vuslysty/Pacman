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
	int		distance;

	static int	indexCounter;

public:

	Cell() = default;
	Cell(int x, int y);
	Cell(Cell const &src);
	Cell	&operator=(Cell const &rhs);


	int 		getDistance() const;
	int			getIndex() const;
	int			getIndexCounter() const;
	Point	&getPos();


	void 		setDistance(int dist);
};


#endif //PACMAN_CELL_HPP
