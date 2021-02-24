#include "tui.h"
#include <sys/ioctl.h>
#include <unistd.h>

struct winsize WhatSize()
{
	struct winsize w;
    	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w;
}

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
	printf("\e[47m");
	for (i = 0; i < length; i++)
	{
		printf(" ");
		GoTo(y_start, x_start + i + 1);
	}
	printf(" \e[0m");				//вспомнить, как убрать эту некрасивость из кода
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

void DrawFlame(int lines, int columns)
{
////////с помощью прохода по экрану
	/*int i = 0, j = 0;
	for(i = 0; i < (columns - 1); i++)	
		printf("*");

	for(j = 0; j < (lines - 3); j++)
	{
		printf("**");
		for(i = 1; i < (columns - 1); i++)
			printf(" ");
	}

	for(i = 0; i < (columns + 1); i++)	
		printf("*");*/

////////интересней
	DrawHorisontal(0, 0, columns);
	DrawVertical(1, 0, lines - 2);
	DrawVertical(1, columns, (lines - 2));
	DrawHorisontal(lines -1, 0, columns);
};

Tui :: Tui()
{
	GoTo(0,0); 
	ClearScreen(); 				//очистили экран, надо узнать его размеры
	struct winsize w = WhatSize(); 		//w.ws_row - lines, w.ws_col - columns
 	DrawFlame(w.ws_row,w.ws_col);
	
};

Tui::~Tui()
{

};

void Tui :: draw()
{

};
