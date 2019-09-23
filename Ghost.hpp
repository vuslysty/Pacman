//
// Created by Vladyslav USLYSTYI on 2019-09-16.
//

#ifndef PACMAN_GHOST_HPP
#define PACMAN_GHOST_HPP


#include <string>
#include "Graph.hpp"
#include "Object.hpp"
#include <queue>
#include <map>
#include <vector>
#include "Cell.hpp"

class Ghost : public Object
{
	Graph				&graph;
	std::queue<Cell*>	*path;
	time_t 				t;

	bool				isActive;
	int					color;
	std::string			bodyA;
	std::string			bodyP;

	Cell	*getMinPoint(Point point);
	Cell	*getMaxPoint(Point point);

public:

	Ghost(Graph &g, int x, int y);

	bool	active();

	std::string	getBodyA();
	std::string	getBodyP();

	bool	hasSomePath();
	void	generatePath();
	void	generateHomePath();
	void 	GetAwayFrom(Point *p);
	void	goTo(Point *p);
	void	go();
	void	goHome();

	~Ghost();

	void	doPassive();
	void	doActive();

};


#endif //PACMAN_GHOST_HPP
