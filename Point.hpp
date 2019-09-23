//
// Created by Vladyslav USLYSTYI on 2019-09-18.
//

#ifndef PACMAN_POINT_HPP
#define PACMAN_POINT_HPP

#include <iostream>

class Point
{
	int	x;
	int y;

public:

	Point();
	Point(int x, int y);
	Point(Point const &src);
	Point	&operator=(Point const &rhs);
	bool    operator==(Point const &rhs) const;
	bool    operator<(Point const &rhs) const;

	const int		getX() const;
	const int		getY() const;

	void			setXY(int x, int y);
	void			incrementX();
	void			incrementY();
	void			decrementX();
	void			decrementY();
	Point			tmpIncrementX() const;
	Point			tmpIncrementY() const;
	Point			tmpDecrementX() const;
	Point			tmpDecrementY() const;
};

std::ostream	&operator<<(std::ostream &o, Point const &rhs);


#endif //PACMAN_POINT_HPP
