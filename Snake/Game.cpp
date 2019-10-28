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

Direction Game::key_binding(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Up:
		return Direction::Up;
		break;
	case sf::Keyboard::Key::Down:
		return Direction::Down;
		break;
	case sf::Keyboard::Key::Left:
		return Direction::Left;
		break;
	case sf::Keyboard::Key::Right:
		return Direction::Right;
		break;

	default:
		break;
	}
}

Game::Game()
	:window(sf::VideoMode(num_width* Tile_length, num_height* Tile_length), "Snake Game")
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
	while (window.isOpen())
	{
		timer += clock.getElapsedTime().asSeconds();
		clock.restart();

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		sf::Keyboard::Key key;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) key = sf::Keyboard::Up;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) key = sf::Keyboard::Down;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) key = sf::Keyboard::Left;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) key = sf::Keyboard::Right;

		if (timer > delay) {
			timer = 0;

			if (collide_obstacles()) {
				//gameover
			}
			else if (ate_fruit()) {
				map.update(true);
				snake.update(key_binding(key));
			}
			else {
				map.update();
				snake.update(key_binding(key));
			}
		}
	}
}

void Game::draw()
{
	map.draw(window);
	snake.draw(window);

	window.display();
}
