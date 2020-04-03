#pragma once
#include "screen.h"
#include "game_object.h"
#include <vector>

using namespace Screen;

using SceneP = std::unique_ptr<Scene>;

struct Scene
{
  void clear();
  void addObject(GameObject &&object);
  std::vector<GameObject> objects;

  static SceneP factory();
};
