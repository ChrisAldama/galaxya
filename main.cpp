#include "application.h"
#include "screen.h"
#include "event_loop.h"
#include "sprite.h"

int main()
{
  Application::init();
  auto renderer = Screen::init();

  Sprite ship("./assets/ship.png", renderer);

  while(Event::loop()) {
    Screen::clean(renderer);
    ship.render(renderer);
    Screen::update(renderer);
  }
  Application::quit();
}