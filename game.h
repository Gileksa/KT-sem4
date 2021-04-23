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
	void NewTail(pair<int,int> tail);
	void DeleteTail();
	void set_direct(Direction d);
};

class Game
{
	private:
	View* myview;
	list<Rabbit> rabbits;
	Snake snake;
	list<pair<int,int>> barrier;
	
	public:
	//pair <int,int> newtail;
	pair <int,int> head;
	pair<int,int> w;
	Game(View* v);
	~Game();
	list<Rabbit> Rabbits();
	Snake& GetSnake();
	void update_snake();
	void update_rabbits(pair<int,int> head);
	void update();
	void quit(int key);
	void turn_up();
	list<pair<int,int>> coords_barrier();
	void remove_rabbit(Rabbit r);
	//void update_rabbits(Rabbit r);
};
