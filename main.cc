#include "tui.h"
#include "gui.h"
#include "game.h"
#include "controller.h"
#include <string.h>
#include <iostream>

int main(int ac, char** av)
{	
	View* v = View::get(ac, av[1]);
	Game m(v);
	Snake& snake = m.GetSnake();

	if(ac < 3)
	{
		HumanC c(v, snake);
	}

	if(ac == 3)
	{
		if((strcmp(av[2], "dump") == 0) || (strcmp(av[2], "d") == 0))
			DumpC c(v, m, snake);
		else
		HumanC c(v, snake);
	}
	v->runloop();

	delete v;
	return 0;
}









//https://habr.com/ru/post/155201/ мейкфайлы для самых маленьких
//https://qastack.ru/programming/2394609/makefile-header-dependencies почитать про зависимости

//https://www.cyberforum.ru/cpp-linux/thread937512.html

//про ESC:
//http://www.linuxdoc.ru/console_codes.html
//http://microsin.net/adminstuff/xnix/ansivt100-terminal-control-escape-sequences.html


//ESC [ ? 25 h
//DECCM (по умолчанию включено): Сделать курсор видимым.
