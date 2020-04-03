#include "application.h"
#include "lib/screen.h"
#include "lib/event_loop.h"
#include "lib/scene.h"
#include "scenes/main/main_scene.h"

int main()
{
  Application::init();
  Screen::init();
  SceneP scene = MainScene::factory();

  while(Event::loop(*scene)) {
    Screen::clean();
    Screen::render(*scene);
    Screen::update();
  }
  Application::quit();
}