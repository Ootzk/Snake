#include "Tile.h"

sf::Sprite get_tile(Tile tiletype)
{
	sf::Texture texture;
	sf::Sprite box;

	switch (tiletype)
	{
	case Tile::BackGround:
		texture.loadFromFile("images/white.png");
		box.setTexture(texture);
		break;

	case Tile::Snake:
		texture.loadFromFile("images/red.png");
		box.setTexture(texture);
		break;

	case Tile::Fruit:
		texture.loadFromFile("images/green.png");
		box.setTexture(texture);
		break;
	}

	return box;
}
