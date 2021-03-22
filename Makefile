CC=g++
CXXFLAGS=-Wall -g
OBJECTS=main.o game.o tui.o controller.o
EXECUTABLE=snake

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJECTS)

clear:
	$(RM) $(OBJECTS) $(EXECUTABLE)
