#pragma once
#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include "screen.h"

using namespace Screen;

struct TextureDeleter {
  void operator()(SDL_Texture *t) { SDL_DestroyTexture(t); }
};

struct SurfaceDeleter {
  void operator()(SDL_Surface *s) { SDL_FreeSurface(s); }
};

using Texture = std::unique_ptr<SDL_Texture, TextureDeleter>;
using Surface = std::unique_ptr<SDL_Surface, SurfaceDeleter>;

class Sprite {
  public:

  bool load(const std::string &path, const Renderer &renderer);
  void render(const Renderer &renderer);
  Sprite(const std::string &path, const Renderer &renderer);

  int width;
  int height;
  int x;
  int y;

  private:
  Texture texture;
};