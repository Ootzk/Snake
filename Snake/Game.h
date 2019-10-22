#pragma once

#include <SFML/Graphics.hpp>

#include <utility>

#include "Map.h"
#include "Snake.h"

class Game
{
private:
	sf::RenderWindow window;
	Map map;
	Snake snake;

public:
	Game(std::pair<int, int> map_size);
	//void draw();
};

