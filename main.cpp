#include "application.h"
#include "screen.h"
#include "event_loop.h"
#include "scene.h"
#include "sprite.h"

int main()
{
  Application::init();
  Screen::init();
  Scene scene;
  Sprite ship("./assets/ship.png", Screen::renderer());
  ship.y = 500;
  Event::Handler handler = [&ship] (const SDL_Event &event) {
    if (event.type == SDLK_a) 
      printf("Left\n");
    if (event.type == SDLK_s)
      printf("Right\n");
    ship.x++;
    printf("X: %i\n", ship.x);
  };

  scene.addObject({ std::move(ship), handler });

  while(Event::loop(scene)) {
    Screen::clean();
    Screen::render(scene);
    Screen::update();
  }
  Application::quit();
}