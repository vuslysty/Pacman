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
	std::string			body;

	Cell	*getMinPoint(Point point);

public:

	Ghost(Graph &g, int x, int y);

	std::string	getBody();

	bool	hasSomePath();
	void	generatePath();
	void	goTo(Point *p);
	void	go();

	~Ghost();

	void	doPassive();
	void	doActive();

};


#endif //PACMAN_GHOST_HPP
