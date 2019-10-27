#pragma once

#include <SFML/Graphics.hpp>

#include <functional>
#include <random>
#include <utility>

/* 2-D Data */
//number of Tiles in window's width and height
const int num_width = 20;
const int num_height = 15;

//Direction
enum class Direction : char {
	Stop,
	Up,
	Down,
	Left,
	Right
};

//Cooridnate
class Coordinate
{
private:
	unsigned int x;
	unsigned int y;

public:
	Coordinate();
	Coordinate(unsigned int x, unsigned int y);
	~Coordinate();

	Coordinate& operator=(const Coordinate &rhs);
	friend bool operator==(const Coordinate& lhs, const Coordinate& rhs);

	unsigned int get_x() const;
	unsigned int get_y() const;

	void move_Up();
	void move_Down();
	void move_Left();
	void move_Right();
};

//Coordinate Factory implemented in factory pattern
class CoordinateFactory
{
private:
	std::mt19937 randomEngine;

	std::uniform_int_distribution<int> distribution_x;
	std::uniform_int_distribution<int> distribution_y;

public:
	CoordinateFactory();
	~CoordinateFactory();

	Coordinate create_randomCoordinate();
	Coordinate create_centerCoordinate();
	Coordinate create_newtailCoordinate(const Coordinate &current_tail, const Direction &current_dir);
	Coordinate create_specificCoordinate(unsigned int x, unsigned int y);
};

/* Drawing Sprite */
//Tile's length (Tile is square)
const int Tile_length = 36;
//Tile
enum class Tile : char {
	BackGround,
	Obstacle,
	Snake,
	Fruit
};

//Tile creator(implemented in Factory method)
sf::Sprite create_Tile(Tile Tiletype);