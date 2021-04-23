#include "gui.h"
using namespace sf;

Gui::Gui()
{
    	window.create(sf::VideoMode(800, 600), "SNAKE");

	sf::Vector2f targetSize(20.0f,20.0f);
	Image rabbit;
	rabbit.loadFromFile("rabbit.png");

	Texture textrabbit;
	textrabbit.loadFromImage(rabbit);

	rabsprite.setTexture(textrabbit);

	rabsprite.setScale(
	targetSize.x / rabsprite.getLocalBounds().width,
	targetSize.y / rabsprite.getLocalBounds().height);
	rabsprite.setPosition(200, 200);
	window.draw(rabsprite);
	
    	while (window.isOpen())
    	{
        //check all the window's events that were triggered since the last iteration of the loop
        	Event event;
        	while (window.pollEvent(event))
        		{
            	// "close requested" event: we close the window
            			if (event.type == sf::Event::Closed)
					window.close();
        		}
        	Gui::draw();
		
		window.draw(rabsprite);
		window.display();
		//
    	}
}


Gui::~Gui()
{
	window.clear(sf::Color::Black);
	window.close();	
}

void DrawHorisontal(Sprite s, int x, int y, int c, sf::RenderWindow &window)
{
	int i;
	for(i = 0; i < c; i++)
	{
		s.setPosition(x,y);
		window.draw(s);
		x+=20;
	}
}

void DrawVertical(Sprite s, int x, int y, int c, sf::RenderWindow &window)
{
	int i;
	for(i = 0; i < c; i++)
	{
		s.setPosition(x,y);
		window.draw(s);
		y+=20;
	}
}

void DrawFrame(sf::RenderWindow &window)
{
	Image grass;
	grass.loadFromFile("grass.png");

	Texture bigwall;
	bigwall.loadFromImage(grass, IntRect(0,0,20,20));

	Sprite wallsprite;
	wallsprite.setTexture(bigwall);

	DrawHorisontal(wallsprite, 0, 0, 40, window);
	DrawHorisontal(wallsprite, 0, 580, 40, window);
	DrawVertical(wallsprite, 0, 20, 560, window);
	DrawVertical(wallsprite, 780, 20, 560, window);
	window.display();
};

void Gui::draw()
{
	window.clear(sf::Color::Black); //очищение экрана
	DrawFrame(window);		//рисует рамочку
}

//46r, 43s
void Gui::DrawList(list<pair<int, int>> object, int color)
{
	for(pair<int,int> it : object)
		DrawSegment(it, color);
}

void Gui::DrawSegment(pair<int, int> object, int color)
{
	switch(color)
	{
		case 46:
		rabsprite.setPosition(object.first, object.second);
		window.draw(rabsprite);
		window.display();
		break;		
	}
}

void Gui::ClearSegment(pair<int, int> object)
{
	//возможно тут ничего и не надо
}

void Gui::SetOnTime(int timeout, timerfn fn)
{
	timer.first = timeout;
	timer.second = fn;
}

void Gui::SetOnKey(keyfn fn)
{
	keys.push_back(fn);
}

/*void Tui::runloop()
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
};*/

void Gui::runloop() //почитать про события
{
	/*//check all the window's events that were triggered since the last iteration of the loop
        event event;
        while (window.pollEvent(event))
        {
		switch(event.type)
		{
        		case sf::Event::Closed
				window.close();	
				break;

			case sf::Event::KeyPressed
			//дописать

		}
        }*/
}

void Gui::quit(){}

pair<int,int> Gui::WhatSize()
{
	return make_pair(800,600);
}


