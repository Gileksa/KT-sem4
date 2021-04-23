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

void Snake::NewTail(pair<int,int> tail)
{
	body.push_front(tail);
};

void Snake::DeleteTail()
{
	body.pop_front();
}

Snake::~Snake()
{

};

void Snake::set_direct(Direction d)
{
	direct = d;
}

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
	w = myview->WhatSize();
	srand(time(NULL));
	for(i = 0; i < 10; i++)
	{
		int x = rand() % (w.second - 6) + 3;
		int y = rand() % (w.first - 6) + 3;
		rabbits.push_back(Rabbit(x,y));
	}
	snake = Snake();
	list<pair<int,int>> snake_body = snake.WhatCoords();
	list<pair<int,int>> rabbits;

	for(i = 0; i < (w.first); i++)
	{
		barrier.push_back(make_pair(0,i));
		barrier.push_back(make_pair(2,i));
		barrier.push_back(make_pair(w.second - 1,i));
		barrier.push_back(make_pair(w.second,i));
	}

	for(i = 2; i < (w.second - 1); i++)
	{
		barrier.push_back(make_pair(i,0));
		barrier.push_back(make_pair(i, w.first - 1));
	}

	for(pair<int,int> it : snake_body)
	{
		barrier.push_back(it);
	}

	for(Rabbit it : Rabbits())
	{
		rabbits.push_back(it.WhatCoords());
	};

	myview->DrawList(rabbits, 46);
	myview->DrawList(snake_body, 43);

	myview->SetOnTime(50, bind(&Game::update, this));
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


void Game::update_snake()
{
	list<pair<int,int>> body = snake.WhatCoords();
	head = body.back();
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
	barrier.push_back(head);
	myview->DrawSegment(head, 43);
	//myview->DrawList(body, 43);

	//стереть хвост
	pair<int,int> tail = body.front();

	list<pair<int,int>>::iterator it = barrier.begin();
	while(it!=barrier.end())
	{
		if((*it) == tail)
		{
			barrier.erase(it);
			break;
		}
		else 
			it++;
	}
	myview->ClearSegment(tail);
	snake.DeleteTail();
	//myview->DrawList(barrier, 49);
};

void Game::update_rabbits(pair<int,int> head)
{
	list<Rabbit>::iterator it = rabbits.begin();
	while(it!=rabbits.end())
	{
		if((*it).WhatCoords() == head)
		{
			remove_rabbit(*it);
			break;
		}
		else 
			it++;
	}
};

void Game::update()
{
	update_rabbits(head);
	update_snake();
	//for(Rabbit it : rabbits)
	//{
	//	myview->DrawSegment((*it).WhatCoords(), 46);
	//}
};

void Game::remove_rabbit(Rabbit r)
{
	pair<int,int> tail = (snake.WhatCoords()).front();
	list<Rabbit>::iterator it = rabbits.begin();
	while(it!=rabbits.end())
	{
		if((*it).WhatCoords() == r.WhatCoords())
		{
			rabbits.erase(it);
			break;
		}
		else 
			it++;
	}
	snake.NewTail(tail);
	srand(time(NULL));
	int x = rand() % (w.second - 6) + 3;
	int y = rand() % (w.first - 6) + 3;
	rabbits.push_front(Rabbit(x,y));
	//printf("%d;%d", x, y);
	myview->DrawSegment(make_pair(x,y), 46);
};

list<pair<int,int>> Game::coords_barrier()
{
	return barrier;
};


Game::~Game()
{

};

