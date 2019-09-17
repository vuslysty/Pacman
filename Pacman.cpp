//
// Created by Vladyslav USLYSTYI on 2019-09-16.
//

#include "Pacman.hpp"

Pacman::Pacman(int x, int y)
{
	body = "Pa";

	posX = x;
	posY = y;
}

std::string Pacman::getBody()
{
	return body;
}
