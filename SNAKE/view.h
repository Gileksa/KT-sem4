#pragma once

#include "game.h"

class View
{
	virtual void draw() = 0;
		
	public:
	virtual ~View() {} //деструктор не может быть абстрактным
	virtual struct winsize WhatSize() = 0;
	virtual void DrawRabbit(class Rabbit rabbit) = 0;

};

