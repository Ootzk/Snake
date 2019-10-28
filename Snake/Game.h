#pragma once

#include <SFML/Graphics.hpp>

#include "Data.h"
#include "Map.h"
#include "Snake.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Clock clock;
	float timer = 0;
	float delay = 0.1;

	Map map;
	Snake snake;

private:
	bool collide_obstacles();
	bool ate_fruit();

	Direction key_binding(sf::Keyboard::Key key);

public:
	Game();
	~Game();

	void init();
	void update();
	void draw();
};

