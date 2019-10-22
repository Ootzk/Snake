#pragma once

#include <SFML/Graphics.hpp>

#include <utility>

#include "Tile.h"

class Map
{
private:
	static sf::Sprite sprite;

	std::pair<int, int> map_size;

public:
	Map(int map_width, int map_height);
	~Map();

	std::pair<int, int> get_map_size();

	void draw(sf::RenderWindow& window);
};

class MapFactory
{
private:

};