#include "tui.h"
#include "gui.h"

#include <string.h>
#include <iostream>

int main(int ac, char** av)
{
	printf("\e[!l");
	View *v;
	
	/*if(strcmp(av[1], "gui"))
	{
		v = new Gui;
		
	}
	
	else
	{
		v = new Tui;
		
	}*/

	v = new Tui;
	Game m(v);
	list<Rabbit> rabbits = m.Rabbits();
	v->DrawRabbit(rabbits.back());
	list<Coord> snake = m.Snake();
	v->DrawSnake(snake);

	getchar();
	printf("\e[?h");
	//delete v;
	return 0;
}









//https://habr.com/ru/post/155201/ мейкфайлы для самых маленьких

//https://www.cyberforum.ru/cpp-linux/thread937512.html

//про ESC:
//http://www.linuxdoc.ru/console_codes.html
//http://microsin.net/adminstuff/xnix/ansivt100-terminal-control-escape-sequences.html


//ESC [ ? 25 h
//DECCM (по умолчанию включено): Сделать курсор
//видимым.
