CC=g++
CXXFLAGS=-Wall -g
OBJECTS=main.o game.o tui.o controller.o gui.o view.o
EXECUTABLE=snake
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJECTS) $(LIBS)

clear:
	$(RM) $(OBJECTS) $(EXECUTABLE)

depend:
	$(CC) -MM $(CXXFLAGS) $(OBJ:.o=.cc) > .depend

-include .depend
