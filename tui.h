#pragma once

#include <stdio.h>
#include "view.h"
#include <functional>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

class Tui: public View //чтобы была возможность запустить конструктор view
{
	private:
	void draw();

	static function<void(void)> onwinch;
	static void winch(int n);

	public:
	Tui();
	~Tui();

	struct winsize WhatSize();
	void DrawList(list<Coord> object, int color);

};
