#pragma once

#include <stdio.h>
#include "view.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <unistd.h>

using namespace std;


class Tui: public View //чтобы была возможность запустить конструктор view
{
	private:
	void draw();
	bool running;

	static function<void(void)> onwinch;
	static void winch(int n);
	struct termios orig_termios;

	public:
	Tui();
	~Tui();
	
	pair<int, timerfn> timer;
	list<keyfn> keys;

	pair<int,int> WhatSize();
	void DrawList(list<pair<int,int>> object, int color);
	void DrawSegment(pair<int, int> object, int color);
	void ClearSegment(pair<int, int> object);
	void SetOnTime(int timeout, timerfn);
	void SetOnKey(keyfn);
	void runloop();
	void quit();
};
