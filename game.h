#pragma once

#include <list>
#include <iostream>

using namespace std;

class View;

class Rabbit
{
	private:
	pair<int,int> c;

	public:
	Rabbit(int x, int y);
	pair<int,int> WhatCoords();
	~Rabbit();
};

enum Direction {LEFT, RIGHT, UP, DOWN};

class Snake
{
	private:
	list<pair<int,int>> body;
	Direction direct;
	
	public:
	Snake();
	~Snake();
	list<pair<int,int>> WhatCoords();
	Direction WhatDirect();
	void NewHead(pair<int,int> head);
	void DeleteTail();
};

class Game
{
	private:
	View* myview;
	list<Rabbit> rabbits;
	Snake snake;
	
	public:
	Game(View* v);
	~Game();
	list<Rabbit> Rabbits();
	Snake& GetSnake();
	void update_snake();
	void update();
	void quit(int key);
};
