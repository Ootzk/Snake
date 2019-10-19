#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"

#include <iterator>
#include <vector>


enum class Direction : char {
	Up,
	Down,
	Left,
	Right
};

struct coordinate
{
	int x;
	int y;
};

class Snake_Unit
{
private:
	coordinate location;
	static sf::Sprite sprite;

public:
	Snake_Unit(coordinate loc);

	int get_x() const;
	int get_y() const;
	void set_x(int x);
	void set_y(int y);

	sf::Sprite& ref_sprite();
};

class Snake
{
private:
	std::vector<Snake_Unit> body;
	Direction direction;

public:
	Snake()
		: body({ Snake_Unit(coordinate{3, 0}), Snake_Unit(coordinate{2, 0}), Snake_Unit(coordinate{1, 0}), Snake_Unit(coordinate{0, 0}) })
	{

	};
	void tick();
	void draw(sf::RenderWindow& window);
	void set_direction(Direction dir);
};