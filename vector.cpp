#include "vector.hpp"
Vector2::Vector2(int x, int y): x(x), y(y) {
}

Vector2::Vector2() {
    x = 0;
    y = 0;
}

int Vector2::getX() const {
    return x;
}

int Vector2::getY() const {
    return y;
}

Vector2::~Vector2() {
}

void Vector2::add(Vector2 v) {
    x += v.getX();
    y += v.getY();
}

void Vector2::multiply(double m) {
    x *= m;
    y *= m;
}

Vector3::Vector3(int x, int y, int z): x(x), y(y), z(z) {
}

Vector3::~Vector3() {
}


int Vector3::getX() const {
    return x;
}

int Vector3::getY() const {
    return y;
}

int Vector3::getZ() const {
    return z;
}

int Vector3::getR() const {
    return x;
}

int Vector3::getG() const {
    return y;
}

int Vector3::getB() const {
    return z;
}
