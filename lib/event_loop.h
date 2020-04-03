#pragma once

#include <functional>
#include <SDL2/SDL_events.h>
struct Scene;

namespace Event {
  bool loop(Scene &scene);
  using Handler = std::function<void(const SDL_Event &e)>;
}