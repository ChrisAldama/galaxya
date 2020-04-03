#include "sprite.h"
#include "event_loop.h"

struct GameObject {
  Sprite sprite;
  Event::Handler handler;
};