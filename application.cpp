#include "application.h"

bool Application::init()
{
  return (
    SDL_Init(SDL_INIT_VIDEO) &&
    IMG_Init(IMG_INIT_PNG)
  );
}

void Application::quit()
{
  IMG_Quit();
  SDL_Quit();
  exit(0);
}

