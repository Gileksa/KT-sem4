#include "game.h"
#include "tui.h"
#include <time.h>


using namespace std::placeholders;

///////////////////SNAKE/////////////////////////

Snake::Snake()
{
	int i;
	pair<int,int> c = make_pair(5,5);
	for(i = 1; i < 7; i++)//начальная длина - 6
	{
		body.push_back(c);
		c.first++;
	};

	direct = RIGHT;
};

list<pair<int,int>> Snake::WhatCoords()
{
	return body;
}

Direction Snake::WhatDirect()
{
	return direct;
}

void Snake::NewHead(pair<int,int> head)
{
	body.push_back(head);
};

void Snake::DeleteTail()
{
	body.pop_front();
}

Snake::~Snake()
{

};

///////////////////RABBIT/////////////////////////

Rabbit::Rabbit(int x, int y)
{
	c.first = x;
	c.second = y;
};

pair<int,int> Rabbit::WhatCoords()
{
	return c;
}


Rabbit::~Rabbit()
{

};

/////////////////////GAME///////////////////////

Game::Game(View* v)
{
	int i;
	myview = v;
	struct winsize w = myview->WhatSize();
	srand(time(NULL));
	for(i = 0; i < 10; i++)
	{
		int x = rand() % (w.ws_col - 6) + 3;
		int y = rand() % (w.ws_row - 6) + 3;
		rabbits.push_back(Rabbit(x,y));
	}
	snake = Snake();

	myview->SetOnTime(500, bind(&Game::update, this));
	myview->SetOnKey(bind(&Game::quit, this, _1));
}; 

void Game::quit(int key)
{
	if(key == 'q')
		myview->quit();
}

list<Rabbit> Game::Rabbits()
{
	return rabbits;
};

Snake& Game::GetSnake()
{
	return snake;
};

//обновление
void Game::update_snake()
{
	//новая голова
	list<pair<int,int>> body = snake.WhatCoords();
	pair<int,int> head = body.back();
	switch(snake.WhatDirect())
	{
		case RIGHT:
			head.first++;
			break;
		case LEFT:
			head.first--;
			break;
		case UP:
			head.second--;
			break;
		case DOWN:
			head.second++;
			break;
			
	}
	snake.NewHead(head);
	myview->DrawSegment(head, 43);

	//стереть хвост
	pair<int,int> tail = body.front();
	myview->ClearSegment(tail);
	snake.DeleteTail();
};

void update_rabbits(list<Rabbit> r)
{

};

void Game::update()
{
	update_snake();
	update_rabbits(rabbits);
};


Game::~Game()
{

};

