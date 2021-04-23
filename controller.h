#pragma once

#include "game.h"
#include "view.h"
#include <iostream>
#include <functional>
using namespace std;
using timerfn = std::function<void(void)>;

class View;

class HumanC
{
	private:
	View* myview;
	Snake& mysnake;

	public:
	void OnKey(int key);
	HumanC(View* v, Snake& s);
	~HumanC();
};

class DumpC
{
	private:
	View* myview;
	Game& mygame;
	Snake& mysnake;

	public:
	//bool eat;
	DumpC(View* v, Game& m, Snake& s);
	~DumpC();
	void control();
	bool get_barrier(pair<int,int> head);
	bool get_rabbit(pair<int,int> head);
};
