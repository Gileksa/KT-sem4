#include "controller.h"

using namespace std::placeholders;

///////////////////HumanC//////////////////////

HumanC::HumanC(View* v, Snake& s) : mysnake(s)
{
	myview = v;
	myview->SetOnKey(bind(&HumanC::OnKey, this, _1)); 
}

HumanC::~HumanC()
{

}

void HumanC::OnKey(int key)
{
	switch(key)
	{
		case 'A':
		mysnake.set_direct(UP);
		break;
		
		case 'B':
		mysnake.set_direct(DOWN);
		break;

		case 'C':
		mysnake.set_direct(RIGHT);
		break;

		case 'D':
		mysnake.set_direct(LEFT);
		break;
	}
}


////////////////////DumpC////////////////////////////

DumpC::DumpC(View* v, Game& m, Snake& s) : mygame(m), mysnake(s)
{
	myview = v;
	myview->SetOnTime(50, bind(&DumpC::control, this));
}

DumpC::~DumpC()
{

}

pair<int,int> nearest_rabbit(pair<int,int> head, list<Rabbit> rabbits)
{
	int distance = 5000;
	pair<int,int> near;
	for(Rabbit it : rabbits)
	{
		pair<int,int> r = it.WhatCoords();
		if ((r.first+r.second) < distance)
		{
			distance = r.first+r.second;
			near = r;
		}
	}
	return near;
}

void DumpC::control()
{
	list<pair<int,int>> body = mysnake.WhatCoords();
	pair<int,int> head = body.back();

	list<Rabbit> rabbits = mygame.Rabbits();
	pair<int,int> newhead, oldhead = head;

	pair<int,int> rab = (rabbits.back()).WhatCoords();

	switch(mysnake.WhatDirect())
	{
		case RIGHT:
			newhead = make_pair(head.first+=1, head.second);
			
			if (get_barrier(newhead) || (oldhead.first == rab.first))
				mysnake.set_direct(DOWN);
			break;

		case LEFT:
			newhead = make_pair(head.first-=1, head.second);
			if (get_barrier(newhead) || (oldhead.first == rab.first))
				mysnake.set_direct(UP);
			break;

		case UP:
			newhead = make_pair(head.first, head.second-=2);
			if (get_barrier(newhead) || (oldhead.second == rab.second))
				mysnake.set_direct(RIGHT);
			break;

		case DOWN:
			newhead = make_pair(head.first, head.second+=1);
			if (get_barrier(newhead) || (oldhead.second == rab.second))
				mysnake.set_direct(LEFT);
			break;
	}
	mygame.update();
}

bool DumpC::get_barrier(pair<int,int> head)
{
	list<pair<int,int>> bar = mygame.coords_barrier();
	for(pair<int,int> it : bar)
	{
		if(it == head)
			return 1;
	}
	return 0;
}




