#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <tr1/memory>
#include "vector.hpp"
#include "playermotion.hpp"
#include "render.hpp"
using namespace std::tr1;

//window constants
const Vector2 DEF_SCREEN_DIMS(800, 450);
const Vector3 DEF_BG_COL(0xFD, 0xF6, 0xE3);
const char * window_title = "Title of window";


int main(int argc, char* args[]) {
    Renderer rend(window_title, DEF_SCREEN_DIMS, DEF_BG_COL);
    const char * filename = "test.bmp";
    shared_ptr<Vector2> pos (new Vector2(100,100));
    int player_id = rend.addBitmap(filename, pos);
    Controller player;
    player.registerRenderer(&rend);
    player.setRenderID(player_id);
    SDL_Event e;
    bool running = true;
    while(running) {
        running = player.getKeys(e);
        player.update();
        rend.renderAll();
    }
    return 0;
}
