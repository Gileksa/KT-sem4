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

enum Direction {LEFT, RIGHT, UP, DOWN};

class Snake
{
	private:
	list<Coord> body;
	Direction direct;
	
	public:
	Snake();
	~Snake();
	list<Coord> WhatCoords();
};

class Game
{
	private:
	View* myview;
	list<class Rabbit> rabbits;
	list<Coord> body;

	public:
	Game(View* v);
	~Game();
	list<Rabbit> Rabbits();
	list<Coord> Snake();
//
//	void update();
};
