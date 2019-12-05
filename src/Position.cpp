#include "Position.hpp"

Position::Position(float x1,float x2):x(x1),y(x2) {}

Position::~Position() {}

float Position::getX() {
  return x;
}

float Position::getY() {
  return y;
}

