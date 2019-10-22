#include "Map.h"

sf::Sprite Map::sprite = get_tile(Tile::BackGround);

Map::Map(int map_width, int map_height)
	:map_size{map_width, map_height}
{

}

Map::~Map()
{
}

std::pair<int, int> Map::get_map_size()
{
	return map_size;
}

void Map::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < num_width; ++i) {
		for (int j = 0; j < num_height; ++j) {
			sprite.setPosition(i * box_length, j * box_length);
			window.draw(sprite);
		}
	}
}
