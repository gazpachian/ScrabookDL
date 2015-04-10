#include "controller.hpp"

Controller::Controller() {
    position = new Vector2(100, 100);
    velocity = new Vector2(0, 0);
}

Controller::applyAcceleration(Vector2 force) {
    velocity = velocity->add(force);
}

Controller::update() {
  velocity= velocity->multiply(0.2); 
  position = position->add(velocity);
}
