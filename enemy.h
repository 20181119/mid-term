#pragma once
#include "game.h"
#include "SDLgameobject.h"
#include "loadParams.h"
class enemy : public SDLgameobject
{
public:
  enemy(const loadParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean() {}
};
