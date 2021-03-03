#pragma once

//#include <utility>
//#include "tui.h"
#include <list>
#include <iostream>

using namespace std;

class View;

struct Coord
{
	int x;
	int y;
};


class Rabbit
{
	private:
	Coord c;

	public:
	Rabbit(int x, int y);
	struct Coord WhatCoords();
	~Rabbit();
};

class Snake
{
	
};

class Game
{
	private:
	View* myview;
	list<class Rabbit> rabbits;

	void update();

	public:
	Game(View* v);
	~Game();
	list<Rabbit> Rabbits();
	
};
