#include <iostream>
#include <ncurses.h>
#include <cstring>
#include <vector>
#include <fstream>
#include "Pacman.hpp"
#include "Food.hpp"
#include <map>

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
			mvprintw((*f).posY, (*f).getPosX(), (*f).getBody().c_str());
	}
}

bool	canMove(std::vector<std::string> &map, int x, int y, Pacman &man)
{
	return (map[man.posY + y][man.posX + x] == ' ' &&
			map[man.posY + y][man.posX + x + 1] == ' ');
}

void	eatFood(Pacman &man, std::map<int, std::vector<Food > > &food)
{
	int	row = man.getPosY();

	if (food[row].size())
	{
		for (std::vector<Food>::iterator f = food[row].begin(); f != food[row].end(); f++)
		{
			if ((*f).getPosY() == man.getPosY() &&
				((*f).getPosX() == man.getPosX() || (*f).getPosX() == man.getPosX() + 1))
			{
				food[row].erase(f);
				return ;
			}
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

//	for (std::vector<std::string>::iterator m = map.begin(); m != map.end(); m++)
//		std::cout << *m << std::endl;

	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);

	Pacman	man(38, 32);

	nodelay(stdscr, TRUE);

	for (;;)
	{
		drawMap(map);
		drawFood(food);
		eatFood(man, food);

		mvprintw(man.getPosY(), man.getPosX(), "%s", (man.getBody()).c_str());

		int ch = getch();

		if (ch == KEY_DOWN && canMove(map, 0, 1, man))
			man.changePos(0, 1);
		if (ch == KEY_UP && canMove(map, 0, -1, man))
			man.changePos(0, -1);
		if (ch == KEY_LEFT && canMove(map, -1, 0, man))
			man.changePos(-1, 0);
		if (ch == KEY_RIGHT && canMove(map, 1, 0, man))
			man.changePos(1, 0);
		if (ch == 27)
			break ;

//		clear();
		werase(stdscr);
//		refresh();
	}





	endwin();



	return 0;
}
//
//	initscr();
//	curs_set(0);
//	noecho();
//	keypad(stdscr, TRUE);
//
//	int x = 5;
//	int y = 5;
//
//	Pacman	man(37, 32);
//
//	nodelay(stdscr, TRUE);
//
//	for (;;)
//	{
//		drawMap(map);
////		mvprintw(y, x, "X");
////
////		int ch = getch();
////		if (ch == KEY_DOWN)  y++;
////		if (ch == KEY_UP)    y--;
////		if (ch == KEY_LEFT)  x--;
////		if (ch == KEY_RIGHT) x++;
//
//		clear();
//		refresh();
//	}
//	endwin();
//
//
//	return 0;
//}





//int main()
//{
//
//	initscr();                   // Переход в curses-режим
//	printw("Hello world!\n");  // Отображение приветствия в буфер
//	refresh();                   // Вывод приветствия на настоящий экран
//	getch();                     // Ожидание нажатия какой-либо клавиши пользователем
//	endwin();                    // Выход из curses-режима. Обязательная команда.
//
//	return 0;
//}