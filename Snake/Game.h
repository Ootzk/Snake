#pragma once

#include <SFML/Graphics.hpp>

#include <utility>

#include "Map.h"
#include "Snake.h"
#include "Data.h"

class Game
{
private:
	sf::RenderWindow window;
	Map map;
	Snake snake;

private:
	bool collide_obstacles();
	bool ate_fruit();

public:
	Game();
	~Game();

	void init();
	void update();
	void draw();
};

