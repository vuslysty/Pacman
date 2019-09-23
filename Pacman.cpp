//
// Created by Vladyslav USLYSTYI on 2019-09-16.
//

#include "Pacman.hpp"

Pacman::Pacman(int x, int y)
{
	body = "Pa";
	lives = 3;
	score = 0;
	pos = Point(x, y);
}

std::string Pacman::getBody()
{
	return body;
}

int Pacman::getLives()
{
	return lives;
}

int Pacman::getScore()
{
	return score;
}

void Pacman::scoreIncrement(int num)
{
	score += num;
}

void Pacman::liveDecrement()
{
	lives--;
}