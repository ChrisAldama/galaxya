#pragma once

#include "lib/game_object.h"

class Ship : public GameObject
{
public:
  Ship();

  void handler(const SDL_Event &e) override;
};