#include "screen.h"
#include "scene.h"
#include <SDL2/SDL.h>

using namespace Screen;

static Window _window;
static Renderer _renderer;

bool Screen::init()
{
  auto *raw_window = SDL_CreateWindow(
      "Galaxya",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      600,
      600,
      SDL_WINDOW_SHOWN
  );
  _window = Window(raw_window);
  auto *raw_renderer = SDL_CreateRenderer(
    _window.get(),
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );
  _renderer = Renderer(raw_renderer);
  return _renderer != nullptr;
}

void Screen::clean()
{
  SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 0xff);
  SDL_RenderClear(_renderer.get());
}

void Screen::update()
{
  SDL_RenderPresent(_renderer.get());
}

void Screen::render(const Scene &scene)
{
  for (const auto &obj: scene.objects) {
    const auto& sprite = obj.sprite;
    const SDL_Rect rect = {
      sprite.x,
      sprite.y,
      sprite.width,
      sprite.height
    };
    SDL_RenderCopy(
      _renderer.get(),
      sprite.texture.get(),
      nullptr,
      &rect
    );
  }
}

const Renderer& Screen::renderer()
{
  return _renderer;
}
