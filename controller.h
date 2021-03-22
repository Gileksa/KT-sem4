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
