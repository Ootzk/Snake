#include "Snake.h"

Snake::~Snake()
{
}

void Snake::grow()
{
	Coordinate new_tail;



}

void Snake::update(Direction new_direction)
{
	auto update_location = [&]() -> void {
		for (auto it = location.rbegin(); it != location.rend(); ++it) {
			*it = *std::next(it);
		}
	};

	switch (direction) {
	case Direction::up:
		update_location();
		direction = new_direction;
		break;
		
	case Direction::down:
		update_location();
		direction = new_direction;
		break;

	case Direction::left:
		update_location();
		direction = new_direction;
		break;

	case Direction::right:
		update_location();
		direction = new_direction;
		break;

	default:
		direction = new_direction;
		break;
	}


	for (auto it = location.rbegin(); it != location.rend(); ++it) {
		switch (direction) {
		case Direction::up:

		}
	}
}
