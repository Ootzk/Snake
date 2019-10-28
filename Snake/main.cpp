#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Map.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(360, 360), "Snake Game");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		sf::Sprite test = create_Tile(Tile::Fruit);
		test.setPosition(0, 0);

		window.clear();
		window.draw(test);
		window.display();
	}

	return 0;
}