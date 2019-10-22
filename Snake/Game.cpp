#include "Game.h"

Game::Game()
	:window(sf::VideoMode(map.get_map_size().first * box_length, map.get_map_size().second * box_length), "Snake Game")
{
	
}