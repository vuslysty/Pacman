//
// Created by Vladyslav USLYSTYI on 2019-09-16.
//

#include "Food.hpp"
#include "Object.hpp"

Food::Food(int x, int y)
{
	points = 1;
	body = ".";

	posX = x;
	posY = y;
}

int Food::getPoints()
{
	return points;
}

std::string Food::getBody()
{
	return body;
}