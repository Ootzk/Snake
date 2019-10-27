#include "Snake.h"

Snake::Snake()
	: tile_snake(create_Tile(Tile::Snake)), body({ Coordinate{num_width / 2, num_height / 2} }), direction(Direction::Stop)
{

}

void Snake::update(Direction new_direction)
{
	for (auto unit = body.rbegin(); unit != std::prev(body.rend()); ++unit) {
		unit = std::next(unit);
	}

	Coordinate& head = body.front();
	switch (direction)
	{
	case Direction::Up:
		head.move_Up();
		break;
		
	case Direction::Down:
		head.move_Down();
		break;
		
	case Direction::Left: 
		head.move_Left();
		break;
		
	case Direction::Right: 
		head.move_Right();
		break;

	default:
		break;
	}

	direction = new_direction;
}

void Snake::draw(sf::RenderWindow & window)
{
	for (auto unit : body) {
		this->tile_snake.setPosition(unit.get_x() * Tile_length, unit.get_y() * Tile_length);
		window.draw(this->tile_snake);
	}
}

bool Snake::collide(const Coordinate& object)
{
	auto it = std::find(body.begin(), body.end(), object);

	if (it != body.end()) {
		return true;
	}
	else {
		return false;
	}
}
