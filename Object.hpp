//
// Created by Vladyslav USLYSTYI on 2019-09-16.
//

#ifndef PACMAN_OBJECT_HPP
#define PACMAN_OBJECT_HPP


class Object
{
public:

	int	posX;
	int posY;

	int	getPosX();
	int getPosY();

	void	changePos(int x, int y);
};


#endif //PACMAN_OBJECT_HPP
