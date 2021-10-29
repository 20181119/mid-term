#include "enemy.h"
enemy::enemy(const loadParams* pParams):SDLgameobject(pParams){}

void enemy::draw()
{
  SDLgameobject::draw();
}

void enemy::update()
{
  m_x+=1;
  m_y+=1;
  m_currentframe=((SDL_GetTicks()/100)%6);
}