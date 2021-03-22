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
//управляет змеей
}
