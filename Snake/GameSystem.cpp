#include "GameSystem.h"

Coordinate::Coordinate()
	: x(0), y(0)
{
}

Coordinate::Coordinate(unsigned int x, unsigned int y)
	: x(x), y(y)
{
}

Coordinate::~Coordinate()
{
}

const unsigned int Coordinate::get_x() const
{
	return x;
}

const unsigned int Coordinate::get_y() const
{
	return y;
}

bool operator==(const Coordinate& lhs, const Coordinate& rhs)
{
	return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}





CoordinateFactory::CoordinateFactory(unsigned int _x_limit, unsigned int _y_limit)
	: x_limit(_x_limit), y_limit(_y_limit), randomEngine(std::random_device()()), dist_x(0, _x_limit), dist_y(0, _y_limit)
{
}

CoordinateFactory::~CoordinateFactory()
{
}

inline Coordinate CoordinateFactory::generate_randomCoordinate()
{
	return Coordinate(dist_x(randomEngine), dist_y(randomEngine));
}

Coordinate CoordinateFactory::generate_randomCoordinate(std::vector<Coordinate> except_Coordinates)
{
	//TODO: exception Coordinate list as argument (such as Wall's Coordinates).
	return Coordinate(dist_x(randomEngine), dist_y(randomEngine));
}

Coordinate CoordinateFactory::generate_centerCoordinate()
{
	return Coordinate(x_limit / 2, y_limit / 2);
}

Coordinate CoordinateFactory::generate_adjacentCoordinate(const Coordinate& base, const Direction& dir)
{
	switch (dir) {
	case Direction::up:
		if (base.get_y() == 0) {
			return base;
		}
		else {
			return Coordinate(base.get_x(), base.get_y() - 1);
		}
		break;

	case Direction::down:
		if (base.get_y() == y_limit) {
			return base;
		}
		else {
			return Coordinate(base.get_x(), base.get_y() + 1);
		}
		break;

	case Direction::left:
		if (base.get_x() == 0) {
			return base;
		}
		else {
			return Coordinate(base.get_x() - 1, base.get_y());
		}
		break;

	case Direction::right:
		if (base.get_x() == x_limit) {
			return base;
		}
		else {
			return Coordinate(base.get_x() + 1, base.get_y());
		}
		break;

	default:
		return base;
		break;
	}
}

Cell::Cell(unsigned int _x, unsigned int _y)
	: Coordinate(_x, _y)
{
}

Cell::Cell(unsigned int _x, unsigned int _y, Object _object)
	: Coordinate(_x, _y), object(_object)
{
}

Cell::~Cell()
{
}

Object Cell::get_object() const
{
	return object;
}

void Cell::set_object(Object new_object)
{
	object = new_object;
}

Grid::Grid(unsigned int _width, unsigned int _height)
	: width(_width), height(_height)
{
	for (int h = 0; h <= height; ++h) {
		grid.push_back(std::vector<Cell>());
		for (int w = 0; w <= width; ++w) {
			grid.at(h).push_back(Cell(w, h));
		}
	}
}

void Grid::set_object(Coordinate coord, Object obj)
{
	if (coord.get_x() < 0 || coord.get_x() > width || coord.get_y() < 0 || coord.get_y() > height) {
		//error case; do nothing at current implement.
	}
	else {
		grid.at(coord.get_x()).at(coord.get_y()).set_object(obj);
	}
}

Object Grid::get_object(Coordinate coord) const
{
	if (coord.get_x() < 0 || coord.get_x() > width || coord.get_y() < 0 || coord.get_y() > height) {
		//error case; do nothing at current implement.
	}
	else {
		return grid.at(coord.get_x()).at(coord.get_y()).get_object();
	}
}
