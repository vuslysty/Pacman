#include <iostream>
#include <ncurses.h>
#include <cstring>
#include <vector>
#include <fstream>
#include "Pacman.hpp"
#include "Food.hpp"
#include <map>
#include "Graph.hpp"


void	drawMap(std::vector<std::string> &map)
{
	int y = 0;

	for (std::vector<std::string>::iterator m = map.begin(); m != map.end(); m++)
		mvprintw(y++, 0, (*m).c_str());
}

void	drawFood(std::map<int, std::vector<Food > > &food)
{
	for (std::map<int, std::vector<Food > >::iterator m = food.begin(); m != food.end(); m++)
	{
		for (std::vector<Food>::iterator f = (*m).second.begin(); f != (*m).second.end(); f++)
			mvprintw((*f).getPos().getY(), (*f).getPos().getX(), (*f).getBody().c_str());
	}
}

bool	canMove(std::vector<std::string> &map, Point pos)
{
	for (int i = 0; i < 2; i++)
	{
		if (map[pos.getY()][pos.getX() + i] != ' ')
			return false;
	}

	return true;
}

void	eatFood(Pacman &man, std::map<int, std::vector<Food > > &food)
{
	int	row = man.getPos().getY();

	if (food[row].size())
		for (std::vector<Food>::iterator f = food[row].begin(); f != food[row].end(); f++)
		{
			Point	manPos1(man.getPos());
			Point	manPos2(man.getPos());

			manPos2.incrementX();
			if ((*f).getPos() == manPos1 || (*f).getPos() == manPos2)
			{
				food[row].erase(f);
				return ;
			}
		}
}

void	fillFoodOnMap(std::vector<std::string> &map,
					  std::map<int, std::vector<Food > > &food)
{
	int row = 0;

	for (std::vector<std::string>::iterator m = map.begin(); m != map.end(); m++, row++)
	{
		int col = 0;
		while ((*m)[col] != '\0')
		{
			if (row >= 14 && row <= 16 && col >= 30 && col <= 51) // Ghosts base without food
				;
			else if (col % 2 == 0 && (*m)[col] == ' ')
				food[row].push_back(Food(col, row));
			col++;
		}
	}
}

int main()
{
	std::map<int, std::vector<Food > >	food;

	std::vector<std::string> map;
	std::string line;
	std::ifstream file;

	file.open("map");
	while (getline(file, line))
		map.push_back(line);

	fillFoodOnMap(map, food);


	Graph	graph(map);

//	initscr();
//	curs_set(0);
//	noecho();
//	keypad(stdscr, TRUE);

	Pacman	man(38, 32);

	graph.bfsStart(man.getPos());

	graph.printDistances();


//	nodelay(stdscr, TRUE);
//
//	for (;;)
//	{
//		drawMap(map);
//		drawFood(food);
//		eatFood(man, food);
//
//		mvprintw(man.getPos().getY(), man.getPos().getX(), "%s", (man.getBody()).c_str());
//
//		int ch = getch();
//
//		Point	manPos = man.getPos();
//
//		if (ch == KEY_DOWN && graph.isCellInMassive(manPos = man.getPos().tmpIncrementY()))
//			man.setPos(manPos);
//		else if (ch == KEY_UP && graph.isCellInMassive(manPos = man.getPos().tmpDecrementY()))
//			man.setPos(manPos);
//		else if (ch == KEY_LEFT && graph.isCellInMassive(manPos = man.getPos().tmpDecrementX()))
//			man.setPos(manPos);
//		else if (ch == KEY_RIGHT && graph.isCellInMassive(manPos = man.getPos().tmpIncrementX()))
//			man.setPos(manPos);
//		else if (ch == 27)
//			break ;
//
////		clear();
//		werase(stdscr);
////		refresh();
//	}
//
//	endwin();



	return 0;
}