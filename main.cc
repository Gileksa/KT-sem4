#include "tui.h"
#include "gui.h"

#include <string.h>
#include <iostream>

int main(int ac, char** av)
{
	printf("\e[!l");
	View *v;

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
