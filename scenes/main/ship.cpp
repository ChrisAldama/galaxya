#include "ship.h"
#include "lib/sprite.h"
#include "lib/screen.h"

Ship::Ship()
{
  sprite = Sprite("../assets/ship.png", Screen::renderer());
  sprite.y = 500;
  sprite.x = 300;
}

void Ship::handler(const SDL_Event &e)
{
  if (e.type != SDL_KEYDOWN)
    return;

  switch (e.key.keysym.sym)
  {
  case SDLK_LEFT:
    this->sprite.x-=10;
    break;
  case SDLK_RIGHT:
    this->sprite.x+=10;
    break;
  default:
    break;
  }
}