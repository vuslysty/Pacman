//
// Created by Vladyslav USLYSTYI on 2019-09-16.
//

#include "Object.hpp"

int Object::getPosX()
{
	return posX;
}

int Object::getPosY()
{
	return posY;
}

void Object::changePos(int x, int y)
{
	posX += x;
	posY += y;
}