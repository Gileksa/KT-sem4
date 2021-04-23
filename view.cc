#include "view.h"
#include "gui.h"
#include "tui.h"
#include <string.h>

View* View::get(int ac, char* s/* = "tui"*/)
{
	static View* v;
	if(ac == 1)
	{
		v = new Tui;
		return v;
	}
	if(((strcmp(s, "gui")) == 0) || ((strcmp(s, "g")) == 0))
		v = new Gui;
	else
		v = new Tui;
	return v;
}
