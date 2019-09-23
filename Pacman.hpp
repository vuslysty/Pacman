//
// Created by Vladyslav USLYSTYI on 2019-09-16.
//

#ifndef PACMAN_PACMAN_HPP
#define PACMAN_PACMAN_HPP


#include <string>
#include "Object.hpp"

class Pacman : public Object
{
	int			lives;
	int 		score;
	std::string	body;

public:
	Pacman(int x, int y);

	int			getLives();
	int			getScore();
	std::string	getBody();

	void		scoreIncrement(int num);
	void		liveDecrement();

};


#endif //PACMAN_PACMAN_HPP
