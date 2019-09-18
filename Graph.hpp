//
// Created by Vladyslav USLYSTYI on 2019-09-18.
//

#ifndef PACMAN_GRAPH_HPP
#define PACMAN_GRAPH_HPP


#include <map>
#include <vector>
#include "Cell.hpp"
#include <string>

class Graph
{
	std::map<int, std::map<int, Cell> >		cells;
	std::map<Point, std::vector<Cell*> >	graph;

	void	fillCellMassive(std::vector<std::string> &map);
	void	fillGraph();

	Graph() = default;

public:

	Graph(std::vector<std::string> &map);

	bool	isCellInMassive(Point p);
	const std::map<Point, std::vector<Cell*> > &getGraph() const;
};


#endif //PACMAN_GRAPH_HPP