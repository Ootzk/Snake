#pragma once

#include <SFML/Graphics.hpp>

#include <algorithm>
#include <vector>

#include "Data.h"
#include "Snake.h"

class Map
{
private:
	CoordinateFactory coordinate_generator;

private:
	sf::Sprite tile_background;
	sf::Sprite tile_obstacle;
	sf::Sprite tile_fruit;

	std::vector<Coordinate> obstacles;
	Coordinate fruit;

public:
	Map();
	~Map();

	void update(bool newfruit);
	void draw(sf::RenderWindow& window);

	const Coordinate get_fruit() const;
	const std::vector<Coordinate>& get_obstacles() const;
};