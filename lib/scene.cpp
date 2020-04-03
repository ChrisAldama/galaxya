#include "scene.h"

void Scene::addObject(GameObjectP &object)
{
  objects.push_back(std::move(object));
}

void Scene::clear()
{
  objects.clear();
}

SceneP Scene::factory()
{
  return SceneP(new Scene());
}