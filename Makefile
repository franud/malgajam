OBJS = main.cpp game.cpp settings.cpp player.cpp

CC = g++

COMPILER_FLAGS = -w -g

LINKER_FLAGS = -lraylib

OBJ_NAME = bin

all : $(OBJS) 
	g++ $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run: $(OBJ_NAME)
	./$(OBJ_NAME)

clean:
	rm bin 
