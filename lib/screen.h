#pragma once

#include <memory>
#include <SDL2/SDL.h>

struct Scene;

namespace Screen {
  struct WindowDeleter {
    void operator() (SDL_Window *w) { SDL_DestroyWindow(w); }
  };

  struct RendererDeleter {
    void operator() (SDL_Renderer *r) { SDL_DestroyRenderer(r); }
  };

  using Window = std::unique_ptr<SDL_Window, WindowDeleter>;
  using Renderer = std::unique_ptr<SDL_Renderer, RendererDeleter>;

  bool init();
  void clean();
  void update();
  void render(const Scene &scene);
  const Renderer& renderer();
}