#include "tui.h"
#include "gui.h"

#include <string.h>
#include <iostream>

int main(int ac, char** av)
{
	
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

	getchar();

	//delete v;
	return 0;
}
