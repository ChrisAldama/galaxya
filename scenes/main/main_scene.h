#pragma once

#include "lib/scene.h"
#include "lib/game_object.h"

class MainScene : public Scene {
public:
  MainScene();
  static SceneP factory();
};

