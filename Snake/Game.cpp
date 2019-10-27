#include "Game.h"

bool Game::collide_obstacles()
{
	for (auto obstacle : map.get_obstacles()) {
		if (snake.collide(obstacle)) {
			return true;
		}
	}

	return false;
}

bool Game::ate_fruit()
{
	if (snake.collide(map.get_fruit())) {
		return true;
	}
	else {
		return false;
	}
}

Game::Game()
	:window(sf::RenderWindow(sf::VideoMode(480, 360), "Snake Game"))
{
}

Game::~Game()
{
}

void Game::init()
{
	map.draw(window);
	snake.draw(window);
}

void Game::update()
{
	if (collide_obstacles()) {
		//gameover
	}
	else if (ate_fruit()) {
		map.update(true);
		snake.update();
	}
	else {

	}
}
