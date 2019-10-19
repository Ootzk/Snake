#include "Snake.h"

Snake_Unit::Snake_Unit(coordinate loc)
	: location(loc)
{


}

int Snake_Unit::get_x() const
{
	return location.x;
}

int Snake_Unit::get_y() const
{
	return location.y;
}

void Snake_Unit::set_x(int x)
{
	location.x = x;
}

void Snake_Unit::set_y(int y)
{
	location.y = y;
}

sf::Sprite & Snake_Unit::ref_sprite()
{
	return sprite;
}

sf::Sprite Snake_Unit::sprite = get_tile(Tile::Snake);

void Snake::tick()
{
	for (auto unit = body.rbegin(); unit != std::prev(body.rend()); ++unit) {
		unit->set_x(std::next(unit)->get_x());
		unit->set_y(std::next(unit)->get_y());
	}

	Snake_Unit& head = body.front();

	switch (direction)
	{
	case Direction::Up:
		head.set_y(head.get_y() - 1);
		break;
		
	case Direction::Down:
		head.set_y(head.get_y() + 1);
		break;
		
	case Direction::Left: 
		head.set_x(head.get_x() - 1);
		break;
		
	case Direction::Right: 
		head.set_x(head.get_x() + 1);
		break;
	}
}

void Snake::draw(sf::RenderWindow & window)
{
	for (auto unit : body) {
		auto body_tile = unit.ref_sprite();
		body_tile.setPosition(unit.get_x() * box_length, unit.get_y() * box_length);
		window.draw(body_tile);
	}
}

void Snake::set_direction(Direction dir)
{
	direction = dir;
}
