#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"

#include <iterator>
#include <vector>
#include <utility>

enum class Direction : char {
	Stop,
	Up,
	Down,
	Left,
	Right
};

using coordinate = std::pair<int, int>;

class Snake_Unit
{
private:
	coordinate location;

public:
	Snake_Unit(coordinate loc);

	int get_x() const;
	int get_y() const;
	void set_x(int x);
	void set_y(int y);
};

class Snake
{
private:
	static sf::Sprite sprite;

	std::vector<Snake_Unit> body;
	Direction direction;

public:
	Snake();
	void update();
	void draw(sf::RenderWindow& window);
	void set_direction(Direction dir);
};