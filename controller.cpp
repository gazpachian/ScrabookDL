#include "controller.hpp"
using namespace std::tr1;

Controller::Controller() {
    shared_ptr<Vector2> pos (new Vector2(100, 100));
    shared_ptr<Vector2> vel (new Vector2(0, 0));
    position = pos;
    velocity = vel;
}


Controller::Controller(int x, int y) {
    shared_ptr<Vector2> pos (new Vector2(x, y));
    shared_ptr<Vector2> vel (new Vector2(0, 0));
    position = pos;
    velocity = vel;
}

/* This method UGLY tho.*/
bool Controller::getKeys(SDL_Event e) {
    bool ret = true;
    while(SDL_PollEvent(&e) != 0) {
        if(e.type == SDL_QUIT) {
            ret = false;
        }
        else if(e.type == SDL_KEYDOWN) {
            if(e.key.keysym.sym == SDLK_UP){
                is_key_up = true;
            }
            else if(e.key.keysym.sym == SDLK_DOWN){
                is_key_down = true;
            }
            else if(e.key.keysym.sym == SDLK_LEFT){
                is_key_left = true;
            }
            else if(e.key.keysym.sym == SDLK_RIGHT){
                is_key_right = true;
            }
        }
        else if(e.type == SDL_KEYUP) {
            if(e.key.keysym.sym == SDLK_UP){
                is_key_up = false;
            }
            else if(e.key.keysym.sym == SDLK_DOWN){
                is_key_down = false;
            }
            else if(e.key.keysym.sym == SDLK_LEFT){
                is_key_left = false;
            }
            else if(e.key.keysym.sym == SDLK_RIGHT){
                is_key_right = false;
            }
        }
    }
    return ret;
}


void Controller::applyAcceleration(Vector2 force) {
    velocity->add(force);
}

void Controller::setRenderID(int id) {
    render_id = id;
}

void Controller::registerRenderer(Renderer * r) {
    renderer = r;
}

void Controller::update() {
    if(is_key_up)
        applyAcceleration(Vector2(0, -2));
    if(is_key_down)
        applyAcceleration(Vector2(0, 2));
    if(is_key_left)
        applyAcceleration(Vector2(-2, 0));
    if(is_key_right)
        applyAcceleration(Vector2(2, 0));
    position->add(*velocity);
    velocity->multiply(0.85); 
    renderer->updatePosition(render_id, position);
}

Controller::~Controller() {

}
