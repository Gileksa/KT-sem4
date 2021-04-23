#pragma once

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "view.h"
#include <poll.h>

class Gui : public View
{
	private:
	sf::RenderWindow window;	
	void draw(); 
	//bool running;

	public:
	
	sf::Sprite rabsprite;

	Gui();
	~Gui();

	pair<int, timerfn> timer;
	list<keyfn> keys;

	pair<int,int> WhatSize();
	void DrawList(list<pair<int, int>> object, int color) ;
	void DrawSegment(pair<int, int> object, int color);
	void ClearSegment(pair<int, int> object);
	void SetOnTime(int timeout, timerfn);
	void SetOnKey(keyfn);
	void runloop();
	void quit();
};
