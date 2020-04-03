#pragma once
#include "screen.h"
#include "game_object.h"
#include <vector>

using namespace Screen;

struct Scene
{
  void clear();
  void addObject(GameObject &&object);
  std::vector<GameObject> objects;
};