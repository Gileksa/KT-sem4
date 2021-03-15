#include "tui.h"
#include "gui.h"
#include "game.h"
#include <string.h>
#include <iostream>

int main(int ac, char** av)
{
	//printf("\e[!l");
	View *v;

	v = new Tui;
	Game m(v);
	
	list<Coord> snake = m.Snake();
	list<Coord> rabbits;
	for(Rabbit it : m.Rabbits())
	{
		rabbits.push_back(it.WhatCoords());
	};

	v->DrawList(rabbits, 46);
	v->DrawList(snake, 43);
	
	getchar();
	//printf("\e[?h");
	return 0;
}









//https://habr.com/ru/post/155201/ мейкфайлы для самых маленьких

//https://www.cyberforum.ru/cpp-linux/thread937512.html

//про ESC:
//http://www.linuxdoc.ru/console_codes.html
//http://microsin.net/adminstuff/xnix/ansivt100-terminal-control-escape-sequences.html


//ESC [ ? 25 h
//DECCM (по умолчанию включено): Сделать курсор видимым.
