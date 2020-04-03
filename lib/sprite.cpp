#include "sprite.h"
#include <SDL2/SDL_image.h>
#include <stdio.h>

Sprite::Sprite(const std::string &path, const Renderer &renderer):
x(0),
y(0)
{
  if (!load(path, renderer)) {
    printf("Failed to load %s\n", path.c_str());
  }
}

Sprite::Sprite()
{

}

bool Sprite::load(const std::string &path, const Renderer &renderer)
{
  auto *raw_surface = IMG_Load(path.c_str());
  if (!raw_surface) return false;
  Surface surface(raw_surface);

  SDL_SetColorKey(
    surface.get(),
    SDL_TRUE,
    SDL_MapRGB(surface->format, 0, 0xff, 0xff)
  );

  auto *raw_texture = SDL_CreateTextureFromSurface(
    renderer.get(),
    surface.get()
  );
  if (!raw_texture) return false;

  texture = Texture(raw_texture);
  width = surface->w;
  height = surface->h;
  return true;
}
