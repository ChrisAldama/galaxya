#pragma once
#include <memory>
#include <SDL2/SDL.h>

namespace Screen {
  struct WindowDeleter {
    void operator() (SDL_Window *w) { SDL_DestroyWindow(w); }
  };

  struct RendererDeleter {
    void operator() (SDL_Renderer *r) { SDL_DestroyRenderer(r); }
  };

  using Window = std::unique_ptr<SDL_Window, WindowDeleter>;
  using Renderer = std::unique_ptr<SDL_Renderer, RendererDeleter>;

  Renderer init();
  void clean(const Renderer &renderer);
  void update(const Renderer &renderer);
}