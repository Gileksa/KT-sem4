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

void SetColor(int color)
{
	printf("\e[%dm", color);
}

void Put(int x)
{
	for (int i = 0; i < x; i++)
		printf(" ");
}

void DrawHorisontal(int y_start, int x_start, int length)
{
	int i;

	GoTo(y_start, x_start);
	SetColor(47);		//меняет цвет фона на белый
	for (i = 0; i < length; i++)
	{
		Put(1);
		GoTo(y_start, x_start + i + 1);
	}
	SetColor(0);
};

void DrawVertical(int y_start, int x_start, int length)
{
	int i;

	GoTo(y_start, x_start);
	SetColor(47);
	for (i = 0; i < length; i++)
	{
		Put(2);
		GoTo((y_start + i + 1), x_start);
	}
	Put(2);
	SetColor(0);
}


void DrawFrame(int lines, int columns)
{
	DrawHorisontal(0, 0, columns);
	DrawVertical(1, 0, lines - 2);
	DrawVertical(1, columns - 1, (lines - 2));
	DrawHorisontal(lines -1, 0, columns);
};

void Tui :: draw()
{
	GoTo(0,0); 
	ClearScreen(); 				
	struct winsize w = WhatSize(); 		
 	DrawFrame(w.ws_row,w.ws_col);
};

Tui::~Tui()
{
	
};


//это надо переделать. пусть оно просто рисует список, хотя бы всё белого цвета


/*void Tui::DrawRabbit(class Rabbit rabbit)
{
	Coord c = rabbit.WhatCoords();
	GoTo(c.y, c.x);
	printf("\e[46m \e[0m");
};*/

void Tui::DrawList(list<Coord> object, int color)
{
	SetColor(color);
	for(Coord it : object)
	{
		GoTo(it.y,it.x);
		printf(" ");
	};
	SetColor(0);
}

/*void Tui::DrawSnake(list<Coord> snake)
{
	printf("\e[43m");
	for(Coord it : snake)
	{
		GoTo(it.y,it.x);
		printf(" ");
	};

	printf("\e[0m");
};*/





