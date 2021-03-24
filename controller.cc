#include "controller.h"

using namespace std::placeholders;

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
