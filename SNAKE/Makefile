CC=g++
CFLAGS=-Wall -g
OBJECTS=main.o game.o tui.o
EXECUTABLE = snake

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) -o $(EXECUTABLE) $(OBJECTS)

clear:
	$(RM) $(OBJECTS) $(EXECUTABLE)
