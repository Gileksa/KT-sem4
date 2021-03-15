#pragma once

#include "game.h"
#include <list>

class View
{
	virtual void draw() = 0;
		
	public:
	virtual ~View() {} //деструктор не может быть абстрактным
	virtual struct winsize WhatSize() = 0;
	virtual void DrawList(list<Coord> object, int color) = 0;

};

