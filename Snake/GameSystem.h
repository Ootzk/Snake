#pragma once

#include <algorithm>
#include <random>
#include <vector>

enum class Object
{
	background,
	snake,
	fruit,
	wall
};

enum class Direction
{
	stop,
	up,
	down,
	left,
	right
};

class Coordinate
{
private:
	unsigned int x;
	unsigned int y;

public:
	Coordinate();
	Coordinate(unsigned int x, unsigned int y);
	virtual ~Coordinate();

	friend bool operator==(const Coordinate& lhs, const Coordinate& rhs);

	const unsigned int get_x() const;
	const unsigned int get_y() const;
};

class CoordinateFactory
{
private:
	unsigned int x_limit;
	unsigned int y_limit;

private:
	std::mt19937 randomEngine;
	std::uniform_int_distribution<int> dist_x;
	std::uniform_int_distribution<int> dist_y;

public:
	CoordinateFactory(unsigned int _x_limit, unsigned int _y_limit);
	virtual ~CoordinateFactory();

	Coordinate generate_randomCoordinate();
	Coordinate generate_randomCoordinate(std::vector<Coordinate> except_Coordinates);
	Coordinate generate_centerCoordinate();
	Coordinate generate_adjacentCoordinate(const Coordinate &base, const Direction &dir);
};

class Cell: public Coordinate
{
private:
	Object object = Object::background;

public:
	Cell(unsigned int _x, unsigned int _y);
	Cell(unsigned int _x, unsigned int _y, Object _object);
	virtual ~Cell();

	Object get_object() const;
	void set_object(Object new_object);
};

class Grid
{
private:
	unsigned int width;
	unsigned int height;

private:
	std::vector<std::vector<Cell>> grid;

public:
	Grid(unsigned int _width, unsigned int _height);

	void set_object(Coordinate coord, Object obj);
	Object get_object(Coordinate coord) const;
};