#pragma once

#include <iterator>
#include <vector>

#include "GameSystem.h"
#include "Map.h"

class Snake
{
private:
	std::vector<Coordinate> location;
	Direction direction = Direction::stop;

public:
	Snake() = default;
	virtual ~Snake();

	friend void Map::load(Snake& snake);

	//void init(map_file m);
	void grow();
	void update(Direction new_direction);
};

