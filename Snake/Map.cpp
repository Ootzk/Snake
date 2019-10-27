#include "Map.h"

Map::Map()
	: tile_background(create_Tile(Tile::BackGround)), tile_obstacle(create_Tile(Tile::Obstacle)), tile_fruit(create_Tile(Tile::Fruit))
{
}

Map::~Map()
{
}

void Map::update(bool newfruit)
{
	if (newfruit == true) {
		fruit = coordinate_generator.create_randomCoordinate();
	}
}

void Map::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < num_width; ++i) {
		for (int j = 0; i < num_height; ++j) {
			tile_background.setPosition(i * Tile_length, j * Tile_length);
			window.draw(tile_background);
		}
	}

	tile_fruit.setPosition(fruit.get_x() * Tile_length, fruit.get_y() * Tile_length);
	window.draw(tile_fruit);
}

const Coordinate Map::get_fruit() const
{
	return fruit;
}

const std::vector<Coordinate>& Map::get_obstacles() const
{
	return obstacles;
}
