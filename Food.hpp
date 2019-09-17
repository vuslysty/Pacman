//
// Created by Vladyslav USLYSTYI on 2019-09-16.
//

#ifndef PACMAN_FOOD_HPP
#define PACMAN_FOOD_HPP


#include <string>
#include "Object.hpp"

class Food : public Object
{
	int			points;
	std::string	body;

public:

	Food(int x, int y);

	int			getPoints();
	std::string	getBody();
};


#endif //PACMAN_FOOD_HPP
