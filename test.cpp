//
// Created by Vladyslav USLYSTYI on 2019-09-18.
//

#include <map>
#include <iostream>


int main()
{
	std::map<int, std::map<int, char> >	map;

	map[3][2] = 's';

	try
	{
		if (map[3].at(2))
			std::cout << map[3][2];
	}
	catch (std::exception &e)
	{
		std::cout << "key not found" << std::endl;
	}

	return (0);
}