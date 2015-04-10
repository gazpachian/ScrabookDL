OBJS = SDLTest.cpp vector.cpp playermotion.cpp render.cpp
HEADERS = vector.hpp playermotion.hpp render.hpp

OBJ_NAME = SDLTest

COMP_FLGS = -Wall -g

CC = clang

LN_FLGS = -lSDL2 -lstdc++

all : $(OBJS) 
	$(CC) $(OBJS) $(COMP_FLGS) $(LN_FLGS) -o $(OBJ_NAME)


