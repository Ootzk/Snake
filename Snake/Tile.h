#pragma once

#include <SFML/Graphics.hpp>

static int box_length = 36;

enum class Tile {
	BackGround,
	Snake,
	Fruit
};

sf::Sprite get_tile(Tile type);