#include "event_loop.h"
#include "SDL2/SDL.h"

bool Event::loop()
{
  static SDL_Event e;
  while(SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) return false;
  }
  return true;
}