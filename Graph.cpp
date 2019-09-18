//
// Created by Vladyslav USLYSTYI on 2019-09-18.
//

#include "Graph.hpp"

void Graph::fillCellMassive(std::vector<std::string> &map)
{
	int row = 0;

	for (std::vector<std::string>::iterator m = map.begin(); m != map.end(); m++, row++)
	{
		int	len = (*m).length();
		int col = 0;

		while (col < len - 1)
		{
			if ((*m)[col] == ' ' && (*m)[col + 1] == ' ')
				cells[row][col] = Cell(col, row);
			col++;
		}
	}
}

void Graph::fillGraph()
{
	for (std::map<int, std::map<int, Cell> >::iterator ceIterY = cells.begin();
			ceIterY != cells.end(); ceIterY++)
	{
		for (std::map<int, Cell>::iterator ceIterX = (*ceIterY).second.begin();
			 ceIterX != (*ceIterY).second.end(); ceIterX++)
		{
			Point	currPos = (*ceIterX).second.getPos();
			Point	tmp[4] = {

					currPos.tmpIncrementX(),
					currPos.tmpIncrementY(),
					currPos.tmpDecrementX(),
					currPos.tmpDecrementY()
			};

			for (int i = 0; i < 4; i++)
				if ( isCellInMassive( tmp[i] ) )
					graph[currPos].push_back(&cells[tmp[i].getY()][tmp[i].getX()]);
		}
	}
}

bool Graph::isCellInMassive(Point p)
{
	try
	{
		cells.at( p.getY() ).at( p.getX() );
		return true;
	} catch (...) {}

	return false;
}

Graph::Graph(std::vector<std::string> &map)
{
	fillCellMassive(map);
	fillGraph();
}

const std::map<Point, std::vector<Cell*> >& Graph::getGraph() const
{
	return graph;
}