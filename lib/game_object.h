#pragma once

#include "sprite.h"
#include "event_loop.h"

class GameObject {
public:
  Sprite sprite;
  virtual void handler(const SDL_Event &e) {};

  GameObject() {};
};