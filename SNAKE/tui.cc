#include "tui.h"

using namespace std;

function<void(void)> Tui::onwinch;

Tui :: Tui()
{
	setbuf(stdout, NULL);			//дебуферизовать для красоты
	draw();					//нарисовать рамочку

	onwinch = bind(&Tui::draw, this);
	signal(SIGWINCH, &Tui::winch);		//для ресайза
};

struct winsize Tui::WhatSize()
{
	struct winsize w;
    	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w;
}

void Tui::winch(int n)
{
	onwinch();
};

void ClearScreen()
{
	printf("\e[2J");
};

void GoTo(int y, int x)
{
	printf("\e[%d;%dH", y, x);
};

void DrawHorisontal(int y_start, int x_start, int length)
{
	int i;

	GoTo(y_start, x_start);
	printf("\e[47m");		//яет цвет фона на белый
	for (i = 0; i < length; i++)
	{
		printf(" ");
		GoTo(y_start, x_start + i + 1);
	}
	printf(" \e[0m");			//вспомнить, как убрать эту некрасивость из кода
						//возвращает чёрный цвет фона	
};

void DrawVertical(int y_start, int x_start, int length)
{
	int i;

	GoTo(y_start, x_start);
	printf("\e[47m");
	for (i = 0; i < length; i++)
	{
		printf("  ");
		GoTo((y_start + i + 1), x_start);
	}
	printf("  \e[0m");
}

void DrawFrame(int lines, int columns)
{
	DrawHorisontal(0, 0, columns);
	DrawVertical(1, 0, lines - 2);
	DrawVertical(1, columns - 1, (lines - 2));
	DrawHorisontal(lines -1, 0, columns);
};

void Tui::DrawRabbit(class Rabbit rabbit)
{
	//переместить курсор в координаты кролика
	struct Coord c = rabbit.WhatCoords();
	GoTo(c.y, c.x);
	printf("\e[46m \e[0m");
};



void Tui :: draw()
{
	GoTo(0,0); 
	ClearScreen(); 				//очистили экран, надо узнать его размеры
	struct winsize w = WhatSize(); 		//w.ws_row - lines, w.ws_col - columns
 	DrawFrame(w.ws_row,w.ws_col);
};

Tui::~Tui()
{
	
};
