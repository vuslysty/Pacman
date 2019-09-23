#include <iostream>
#include <ncurses.h>
#include <cstring>
#include <vector>
#include <fstream>
#include "Pacman.hpp"
#include "Food.hpp"
#include <map>
#include <zconf.h>

#include "Graph.hpp"
#include "Ghost.hpp"

int 	foodCount = 0;


void	drawMap(std::vector<std::string> &map)
{
	int y = 0;

	for (std::vector<std::string>::iterator m = map.begin(); m != map.end(); m++)
		mvprintw(y++, 0, (*m).c_str());

	mvprintw(++y, 5, "Dots on the map: %i", foodCount);
}

void	drawFood(std::map<int, std::vector<Food > > &food)
{
	for (std::map<int, std::vector<Food > >::iterator m = food.begin(); m != food.end(); m++)
	{
		for (std::vector<Food>::iterator f = (*m).second.begin(); f != (*m).second.end(); f++)
			mvprintw((*f).getPos().getY(), (*f).getPos().getX(), (*f).getBody().c_str());
	}
}

bool	isOverlap(Point *p1, Point *p2)
{
	return (p1->getY() == p2->getY() &&
			(p1->getX() == p2->getX() || p1->getX() + 1 == p2->getX() + 1));
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
				foodCount--;
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
			{
				food[row].push_back(Food(col, row));
				foodCount++;
			}
			col++;
		}
	}
}

int main()
{
	bool	fail = false;
	bool	win = false;

	std::map<int, std::vector<Food > >	food;

	std::vector<std::string> map;
	std::string line;
	std::ifstream file;

	file.open("map");
	while (getline(file, line))
		map.push_back(line);

	fillFoodOnMap(map, food);


	Graph	graph(map);


	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);

	Pacman	man(38, 32);
	Ghost	ghost[4] = {
			Ghost(graph, 38, 16),
			Ghost(graph, 38, 15),
			Ghost(graph, 37, 16),
			Ghost(graph, 37, 15),
	};


	nodelay(stdscr, TRUE);

	for (;;)
	{
		drawMap(map);
		drawFood(food);
		eatFood(man, food);

		if (!foodCount)
			win = true;

		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);

		attron(COLOR_PAIR(2));
		mvprintw(man.getPos().getY(), man.getPos().getX(), "%s", (man.getBody()).c_str());
		attroff(COLOR_PAIR(2));

		srand(time(nullptr) * time(nullptr));
		for (int i = 0; i < 4; i++)
		{
			attron(COLOR_PAIR(1));
			mvprintw(ghost[i].getPos().getY(), ghost[i].getPos().getX(), "%s",
					 (ghost[i].getBody()).c_str());
			attroff(COLOR_PAIR(1));

			if (i == 3)
				ghost[i].goTo(&man.getPos());
			else
				ghost[i].go();

			if (isOverlap(&man.getPos(), &ghost[i].getPos()))
				fail = true;
		}



		int ch = getch();

		Point	manPos = man.getPos();

		if (ch == KEY_DOWN && graph.isCellInMassive(manPos = man.getPos().tmpIncrementY()))
			man.setPos(manPos);
		else if (ch == KEY_UP && graph.isCellInMassive(manPos = man.getPos().tmpDecrementY()))
			man.setPos(manPos);
		else if (ch == KEY_LEFT && graph.isCellInMassive(manPos = man.getPos().tmpDecrementX()))
			man.setPos(manPos);
		else if (ch == KEY_RIGHT && graph.isCellInMassive(manPos = man.getPos().tmpIncrementX()))
			man.setPos(manPos);
		else if (ch == 27)
			break ;

//		clear();
		werase(stdscr);

		if (fail || win)
		{
			clear();

			attron(COLOR_PAIR(1));

			if (fail)
				mvprintw(5, 5, "                .-'''-.                                                                         ___      ___      ___   \n"
							   "                   '   _    \\                  _______                             _______       .'/   \\  .'/   \\  .'/   \\  \n"
							   "                 /   /` '.   \\                 \\  ___ `'.   .--.      __.....__    \\  ___ `'.   / /     \\/ /     \\/ /     \\ \n"
							   " .-.          .-.   |     \\  '                  ' |--.\\  \\  |__|  .-''         '.   ' |--.\\  \\  | |     || |     || |     | \n"
							   "  \\ \\        / /|   '      |  '                 | |    \\  ' .--. /     .-''\"'-.  `. | |    \\  ' | |     || |     || |     | \n"
							   "   \\ \\      / / \\    \\     / /                  | |     |  '|  |/     /________\\   \\| |     |  '|/`.   .'|/`.   .'|/`.   .' \n"
							   "    \\ \\    / /   `.   ` ..' /_    _             | |     |  ||  ||                  || |     |  | `.|   |  `.|   |  `.|   |  \n"
							   "     \\ \\  / /       '-...-'`| '  / |            | |     ' .'|  |\\    .-------------'| |     ' .'  ||___|   ||___|   ||___|  \n"
							   "      \\ `  /               .' | .' |            | |___.' /' |  | \\    '-.____...---.| |___.' /'   |/___/   |/___/   |/___/  \n"
							   "       \\  /                /  | /  |           /_______.'/  |__|  `.             .'/_______.'/    .'.--.   .'.--.   .'.--.  \n"
							   "       / /                |   `'.  |           \\_______|/           `''-...... -'  \\_______|/    | |    | | |    | | |    | \n"
							   "   |`-' /                 '   .'|  '/                                                            \\_\\    / \\_\\    / \\_\\    / \n"
							   "    '..'                   `-'  `--'                                                              `''--'   `''--'   `''--'  ");
			else
				mvprintw(5, 5, "                .-'''-.                                                    ___      ___      ___   \n"
							   "                   '   _    \\                                               .'/   \\  .'/   \\  .'/   \\  \n"
							   "                 /   /` '.   \\                              .--.   _..._   / /     \\/ /     \\/ /     \\ \n"
							   " .-.          .-.   |     \\  '                       _     _|__| .'     '. | |     || |     || |     | \n"
							   "  \\ \\        / /|   '      |  '                /\\    \\\\   //.--..   .-.   .| |     || |     || |     | \n"
							   "   \\ \\      / / \\    \\     / /                 `\\\\  //\\\\ // |  ||  '   '  ||/`.   .'|/`.   .'|/`.   .' \n"
							   "    \\ \\    / /   `.   ` ..' /_    _              \\`//  \\'/  |  ||  |   |  | `.|   |  `.|   |  `.|   |  \n"
							   "     \\ \\  / /       '-...-'`| '  / |              \\|   |/   |  ||  |   |  |  ||___|   ||___|   ||___|  \n"
							   "      \\ `  /               .' | .' |               '        |  ||  |   |  |  |/___/   |/___/   |/___/  \n"
							   "       \\  /                /  | /  |                        |__||  |   |  |  .'.--.   .'.--.   .'.--.  \n"
							   "       / /                |   `'.  |                            |  |   |  | | |    | | |    | | |    | \n"
							   "   |`-' /                 '   .'|  '/                           |  |   |  | \\_\\    / \\_\\    / \\_\\    / \n"
							   "    '..'                   `-'  `--'                            '--'   '--'  `''--'   `''--'   `''--'  ");

			attroff(COLOR_PAIR(1));

			refresh();
			getchar();
			getchar();
			getchar();
			getchar();
			break ;
		}

//		refresh();
	}

	endwin();



	return 0;
}