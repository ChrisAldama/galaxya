#include "event_loop.h"
#include "SDL2/SDL.h"
#include "scene.h"

bool Event::loop(const Scene &scene)
{
  static SDL_Event e;
  while(SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) return false;
    for (const auto &obj : scene.objects) {
      obj.handler(e);
    }
  }
  return true;
}