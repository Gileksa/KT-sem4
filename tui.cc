#include "tui.h"
#include <poll.h>
#include <string.h>

using namespace std;

function<void(void)> Tui::onwinch;

Tui :: Tui()
{
	//tcgetattr, запомнили перед тем как испортить cfmakerow, tcsetattr прочитать-поменять-переделать
	struct termios trm;
	tcgetattr(0, &trm);
	orig_termios = trm;
	cfmakeraw(&trm);
    	//new_termios.c_lflag &= ~ECHO;
    	tcsetattr(0, TCSAFLUSH, &trm);

	setbuf(stdout, NULL);			//дебуферизовать для красоты
	draw();					//нарисовать рамочку

	onwinch = bind(&Tui::draw, this);
	signal(SIGWINCH, &Tui::winch);		//для ресайза
}

Tui::~Tui()
{
	//tcsetattr старых значений - вспомнить
	tcsetattr(0, TCSAFLUSH, &orig_termios);
}

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



void Tui::DrawList(list<pair<int,int>> object, int color)
{
	SetColor(color);
	for(pair<int,int> it : object)
	{
		GoTo(it.second,it.first);
		Put(1);
	};
	SetColor(0);
}

void Tui::DrawSegment(pair<int, int> object, int color)
{
	SetColor(color);
	GoTo(object.second,object.first);
	Put(1);
	SetColor(0);
}

void Tui::ClearSegment(pair<int, int> object)
{
	DrawSegment(object, 0);
};

void Tui::SetOnTime(int timeout, timerfn fn)
{
	timer.first = timeout;
	timer.second = fn;
}

void Tui::SetOnKey(keyfn fn)
{
	keys.push_back(fn);
}

struct pollfd fds = {0, POLLIN};

void Tui::runloop()
{
	int p;
	running = true;
	while(running)
	{
		p = poll(&fds, 1, timer.first);
		if(p == 0)
		{
			timer.second();
		};
		if(p == 1)
		{
			int c = getchar();
			for(auto fn : keys)
			{
				fn(c);
			}
		};
	}
};

void Tui::quit() //для проверки, прошла ли подписка на клавиши. Будет выходить при нажатии q, Enter
{
	running = false;
}
