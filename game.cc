#include "game.h"
#include "tui.h"
#include <time.h>


Snake::Snake()
{
	int i;
	Coord c = {5,5};
	for(i = 1; i < 7; i++)
	{
		body.push_back(c);
		c.x++;
	};

	direct = RIGHT;
};

Game::Game(View* v)
{
	myview = v;
	struct winsize w = myview->WhatSize();
	srand(time(NULL));
	int x = rand() % (w.ws_col - 3) + 3;
	int y = rand() % (w.ws_row - 3) + 3;
	rabbits.push_back(Rabbit(x,y));
	class Snake snake;
	body = snake.WhatCoords();
}; 

Game::~Game()
{

};

Rabbit::Rabbit(int x, int y)
{
	c.x = x;
	c.y = y;
};

struct Coord Rabbit::WhatCoords()
{
	return c;
}


Rabbit::~Rabbit()
{

};

list<Rabbit> Game::Rabbits()
{
	return rabbits;
};

list<Coord> Snake::WhatCoords()
{
	return body;
}

list<Coord> Game::Snake()
{
	return body;
};

Snake::~Snake()
{

};

void update()
{

};
