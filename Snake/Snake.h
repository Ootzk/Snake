#pragma once

#include <SFML/Graphics.hpp>

#include <algorithm>
#include <iterator>
#include <vector>

#include "Data.h"
#include "Map.h"

class Snake
{
private:
	sf::Sprite tile_snake;

	std::vector<Coordinate> body;
	Direction direction;

public:
	Snake();
	void update(Direction new_direction);
	void draw(sf::RenderWindow& window);

	bool collide(const Coordinate& object);
};