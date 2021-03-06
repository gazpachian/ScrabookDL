#include "SDLTest.hpp"
using namespace std::tr1;

int main(int argc, char* args[]) {
    Renderer rend(window_title, DEF_SCREEN_DIMS, DEF_BG_COL);
    const char * filename = "tower_51.png";
    shared_ptr<Vector2> pos (new Vector2(100,100));
    int player_id = rend.addImage(filename, pos);
    if(player_id == -1) {
        return -1;
    }
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
