#pragma once

#include "game.h"

class View
{
	virtual void draw() = 0;
	
//у нашего view не будет метода draw, это для наследников. Будет рисовать все, но сам класс его не реализует и не обещает рисовать. virtual - только когда когда он будет исполнять v draw, сможет во время исполнения изучать эту связь. v -> draw() -- комп динамически определяет, туйский или гуйский вариант выбрать. Виртуал включает это слова. Без него не получится ничего хорошего с наследованием. Компилятор ищет draw в соответствующем дочернем классе.
// виртуальному классу особо не нужен конструктор. Можно сделать полностью абстрактный класс и конструктор не опиывать. Но виртуальный деструктор нужен.
	
	public:
	virtual ~View() {} //деструктор не может быть абстрактным
	virtual struct winsize WhatSize() = 0;
	virtual void DrawRabbit(class Rabbit rabbit) = 0;
	virtual void DrawSnake(list<Coord> snake) = 0;

};

