#include "main_scene.h"
#include "ship.h"

MainScene::MainScene() {
  GameObjectP ship(new Ship());
  addObject(ship);
}

SceneP MainScene::factory() {
  return SceneP(new MainScene());
}