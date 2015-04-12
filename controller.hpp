#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include <SDL2/SDL.h>
#include <tr1/memory>
#include "vector.hpp"
#include "render.hpp"
using namespace std::tr1;

class Controller {
    private:
        shared_ptr<Vector2> position;
        shared_ptr<Vector2> velocity;
        Renderer * renderer;
        int render_id;
        bool is_key_up, is_key_down, is_key_left, is_key_right;
    public:
        Controller();
        Controller(int x, int y);
        ~Controller();
        void applyAcceleration(Vector2 force); 
        void setRenderID(int id);
        void registerRenderer(Renderer * r);
        void update();
        bool getKeys(SDL_Event e);
};
#endif
