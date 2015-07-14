OBJS = SDLTest.cpp vector.cpp controller.cpp render.cpp
HEADERS = vector.hpp controller.hpp render.hpp

OBJ_NAME = SDLTest

COMP_FLGS = -Wall -g

CC = clang

LN_FLGS = -lSDL2 -lstdc++ -lSDL2_image

all : $(OBJS) 
	$(CC) $(OBJS) $(COMP_FLGS) $(LN_FLGS) -o $(OBJ_NAME)


