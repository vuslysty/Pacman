//
// Created by Vladyslav USLYSTYI on 2019-09-16.
//

#include "Ghost.hpp"

Ghost::Ghost(Graph &g, int x, int y) : graph(g)
{
	pos = Point(x, y);
	path = new std::queue<Cell*>;
	body = "Gh";
	t = clock();
}

Ghost::~Ghost()
{
	delete path;
}

bool Ghost::hasSomePath()
{
	return (path->size());
}

Cell	*Ghost::getMinPoint(Point point)
{
	Cell							*minCell;
	std::vector<Cell*>::iterator	item;

	item = graph.getGraph().at(point).begin();
	minCell = *item;

	for (item; item != graph.getGraph().at(point).end(); item++)
		if ((*item)->getDistance() < (*minCell).getDistance())
			minCell = *item;
	return minCell;
}

void Ghost::generatePath()
{
	std::map<Point, std::vector<Cell*> >::iterator	randPoint = graph.getGraph().begin();

	std::advance( randPoint, rand() % graph.getGraph().size() );

	graph.bfsStart((*randPoint).first);

	path->push(graph.getCell(pos));
	while (path->back()->getDistance() != 0)
		path->push(getMinPoint(path->back()->getPos()));
}

void Ghost::goTo(Point *p)
{
	if (static_cast<double>(clock() - t) / CLOCKS_PER_SEC  > 0.20)
	{
		graph.bfsStart(*p);
		pos = getMinPoint(pos)->getPos();
		t = clock();
	}
}

void Ghost::go()
{
	double	secPerStroke;

	if (hasSomePath())
	{
		secPerStroke = pos.getY() == path->front()->getPos().getY() ? 0.15 : 0.25;

		if (static_cast<double>(clock() - t) / CLOCKS_PER_SEC  > secPerStroke)
		{
			pos = path->front()->getPos();
			path->pop();
			t = clock();
		}
	}
	else
		generatePath();
}

std::string Ghost::getBody()
{
	return body;
}