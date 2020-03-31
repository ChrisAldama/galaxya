#include "screen.h"
#include <SDL2/SDL.h>

using namespace Screen;

static Window window;

Renderer Screen::init()
{
  auto *raw_window = SDL_CreateWindow(
      "Galaxya",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      600,
      600,
      SDL_WINDOW_SHOWN
  );
  window = Window(raw_window);
  auto *raw_renderer = SDL_CreateRenderer(
    window.get(),
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );
  return Renderer(raw_renderer);
}

void Screen::clean(const Renderer &renderer)
{
  SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0xff);
  SDL_RenderClear(renderer.get());
}

void Screen::update(const Renderer &renderer)
{
  SDL_RenderPresent(renderer.get());
}
