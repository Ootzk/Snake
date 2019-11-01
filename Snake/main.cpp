#include <iostream>

#include "GameSystem.h"

int main()
{
	int width = 8;
	int height = 5;
	CoordinateFactory fac(width, height);

	std::cout << "Random Coordinate Test" << std::endl;
	for (int i = 0; i < 10; ++i) {
		Coordinate generated = fac.generate_randomCoordinate();
		std::cout << "(" << generated.get_x() << ", " << generated.get_y() << ")" << std::endl;
	}

	std::cout << "up down left right Test" << std::endl;
	Coordinate center(width / 2, height / 2);
	std::cout << "base coordinate: " << "(" << center.get_x() << ", " << center.get_y() << ")" << std::endl;
	Coordinate up = fac.generate_upCoordinate(center);
	std::cout << "up coordinate: " << "(" << up.get_x() << ", " << up.get_y() << ")" << std::endl;
	Coordinate down = fac.generate_downCoordinate(center);
	std::cout << "down coordinate: " << "(" << down.get_x() << ", " << down.get_y() << ")" << std::endl;

	std::cout << "Grid Test" << std::endl;
	Grid grid(width, height);

	std::cout << "hello" << std::endl;
}