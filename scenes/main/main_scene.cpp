#include "main_scene.h"
#include "ship.h"

MainScene::MainScene() {
  addObject(Ship());
}

SceneP MainScene::factory() {
  return SceneP(new MainScene());
}