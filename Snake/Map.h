#pragma once

#include <vector>

#include "GameSystem.h"
#include "Snake.h"


class Map : public Grid
{
private:
	CoordinateFactory coordinate_generator;

private:
	Coordinate fruit;

private:
	bool ate() const;
	bool collide() const;

public:
	Map(unsigned int width, unsigned int height);
	virtual ~Map();

	void load(Snake &snake);
	//void load(Wall& wall);

	//void init(map_file m);
	//void update(Snake& snake);

};

