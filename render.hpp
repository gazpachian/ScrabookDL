#ifndef _RENDER_H
#define _RENDER_H
#include <SDL2/SDL.h>
#include <vector>
#include <tr1/memory>
#include "vector.hpp"
using namespace std::tr1;

class Sprite;

class Renderer {
    private:
        SDL_Window * window;
        std::vector<shared_ptr<Sprite> > sprites;
        Vector3 * background_color;
        void blitSprite(Sprite r);
    public:
        Renderer(const char * window_title, Vector2 dims, Vector3 bg_col);
        ~Renderer();
        /* Renders all sprites in the scene.*/
        void renderAll();
        /* Reads in a bitmap from the specified file name. Returns the id used
         * for update of the renderable.*/
        int addBitmap(const char * filename, shared_ptr<Vector2> pos);
        void updatePosition(int sprite_ID, shared_ptr<Vector2> pos);
};

class Sprite {
    private:
        SDL_Surface * sprite;
        shared_ptr<Vector2> position;
    public:
        Sprite();
        ~Sprite();
        void setPosition(shared_ptr<Vector2> pos);
        void setSprite(SDL_Surface * screen_sprite);
        SDL_Surface * getSprite(); 
        shared_ptr<Vector2> getPosition();
};


#endif
