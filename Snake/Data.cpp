#include "Data.h"

Coordinate::Coordinate()
	:x(0),  y(0)
{
}

Coordinate::Coordinate(unsigned int x, unsigned int y)
	:x(x), y(y)
{
}

Coordinate::~Coordinate()
{
}

Coordinate& Coordinate::operator=(const Coordinate &rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;

	return *this;
}

unsigned int Coordinate::get_x() const
{
	return x;
}

unsigned int Coordinate::get_y() const
{
	return y;
}

void Coordinate::move_Up()
{
	if (y != 0) {
		y--;
	}
}

void Coordinate::move_Down()
{
	if (y != num_height) {
		y++;
	}
}

void Coordinate::move_Left()
{
	if (x != 0) {
		x--;
	}
}

void Coordinate::move_Right()
{
	if (x != num_width) {
		x++;
	}
}

bool operator==(const Coordinate& lhs, const Coordinate& rhs)
{
	if (lhs.x == rhs.x && lhs.y == rhs.y) {
		return true;
	}
	else {
		return false;
	}
}

sf::Sprite create_Tile(Tile Tiletype)
{
	sf::Texture texture;
	sf::Sprite box;

	switch (Tiletype)
	{
	case Tile::BackGround:
		texture.loadFromFile("images/white.png");
		box.setTexture(texture);
		break;

	case Tile::Obstacle:
		texture.loadFromFile("images/gray.png");
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

CoordinateFactory::CoordinateFactory()
	:randomEngine(std::random_device{}()), distribution_x(0, num_width), distribution_y(0, num_height)
{
}

CoordinateFactory::~CoordinateFactory()
{
}

Coordinate CoordinateFactory::create_randomCoordinate()
{
	return Coordinate(distribution_x(randomEngine), distribution_y(randomEngine));
}

Coordinate CoordinateFactory::create_centerCoordinate()
{
	return Coordinate(num_width / 2, num_height / 2);
}

Coordinate CoordinateFactory::create_newtailCoordinate(const Coordinate &current_tail, const Direction &current_dir)
{
	switch (current_dir)
	{
	case(Direction::Up):
		return Coordinate(current_tail.get_x(), current_tail.get_y() + 1);
		break;
	case(Direction::Down):
		return Coordinate(current_tail.get_x(), current_tail.get_y() - 1);
		break;
	case(Direction::Left):
		return Coordinate(current_tail.get_x() + 1, current_tail.get_y());
		break;
	case(Direction::Right):
		return Coordinate(current_tail.get_x() - 1, current_tail.get_y());
		break;

	default:
		break;
	}
}

Coordinate CoordinateFactory::create_specificCoordinate(unsigned int x, unsigned int y)
{
	return Coordinate(x, y);
}
