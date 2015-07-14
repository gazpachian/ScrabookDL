#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <tr1/memory>
#include "vector.hpp"
#include "controller.hpp"
#include "render.hpp"

//Window constants
const Vector2 DEF_SCREEN_DIMS(1200, 675);
const Vector3 DEF_BG_COL(0xFD, 0xF6, 0xE3);
const char * window_title = "Title of window";
