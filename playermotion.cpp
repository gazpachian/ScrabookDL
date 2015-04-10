#include "playermotion.hpp"
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

bool Controller::getKeys(SDL_Event e) {
    bool ret = true;
    while(SDL_PollEvent(&e) != 0) {
        if(e.type == SDL_QUIT) {
            ret = false;
        }
        else if(e.type == SDL_KEYDOWN) {
            if(e.key.keysym.sym == SDLK_UP){
                applyAcceleration(Vector2(0, -15));
            }
            else if(e.key.keysym.sym == SDLK_DOWN){
                applyAcceleration(Vector2(0, 15));
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
    velocity->multiply(0.2); 
    position->add(*velocity);
    renderer->updatePosition(render_id, position);
}

Controller::~Controller() {

}
