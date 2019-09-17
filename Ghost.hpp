//
// Created by Vladyslav USLYSTYI on 2019-09-16.
//

#ifndef PACMAN_GHOST_HPP
#define PACMAN_GHOST_HPP


class Ghost
{
	bool	isActive;
	int		color;

public:

	Ghost(int color);

	void	doPassive();
	void	doActive();

};


#endif //PACMAN_GHOST_HPP
