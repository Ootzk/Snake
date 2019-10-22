#include <SFML/Graphics.hpp>

#include "Snake.h"
#include "Tile.h"

int num_width = 30, num_height = 20;
int width = box_length * num_width;
int height = box_length * num_height;

void draw_background(sf::RenderWindow& window, sf::Sprite& background_tile)
{
	for (int i = 0; i < num_width; ++i) {
		for (int j = 0; j < num_height; ++j) {
			background_tile.setPosition(i * box_length, j * box_length);
			window.draw(background_tile);
		}
	}
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(width, height), "Snake game");

	Snake snake;

	sf::Clock clock;
	float timer = 0, delay = 0.1;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) snake.set_direction(Direction::Up);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) snake.set_direction(Direction::Down);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) snake.set_direction(Direction::Left);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) snake.set_direction(Direction::Right);

		if (timer > delay) {
			timer = 0;
			snake.update();
		}

		//////////Draw//////////
		window.clear();
		sf::Sprite background_tile = get_tile(Tile::BackGround);
		draw_background(window, background_tile);
		snake.draw(window);

		window.display();
	}

	return 0;
}