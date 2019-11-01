#include "Map.h"


bool Map::ate() const
{
	Coordinate snake_head = snake.front();
	if (snake_head == fruit) {
		return true;
	}
	else {
		return false;
	}
}

bool Map::collide() const
{
	for (Coordinate body : snake) {
		auto it = std::find(wall.begin(), wall.end(), body);
		if (it != wall.end()) {
			return true;
		}
	}

	return false;
}

Map::Map(unsigned int width, unsigned int height)
	: Grid(width, height), coordinate_generator(width, height)
{
}

Map::~Map()
{
}

void Map::load(Snake& snake)
{
	
}
