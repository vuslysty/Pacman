//
// Created by Vladyslav USLYSTYI on 2019-09-16.
//

#include "Food.hpp"
#include "Object.hpp"

Food::Food(int x, int y)
{
	points = 1;
	body = ".";

	pos = Point(x, y);
}

int Food::getPoints()
{
	return points;
}

std::string Food::getBody()
{
	return body;
}