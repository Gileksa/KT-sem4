#include "game.h"
#include "tui.h"


Game::Game(View* v)
{
	myview = v;
	struct winsize w = myview->WhatSize();
	//printf("\n%d,%d", w.ws_col, w.ws_row);
	int x = rand() % (w.ws_col - 3) + 2;
	int y = rand() % (w.ws_row - 3) + 2;
	rabbits.push_back(Rabbit(x,y));
}; 

Game::~Game()
{

};

//конструктор для змейки, конструктор для кроликов -- принимает на вход координаты и 

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

void update()
{

};
