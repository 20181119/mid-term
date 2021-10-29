#include "player.h"

player::player(const loadParams* pParams):SDLgameobject(pParams){}

void player::draw()
{
  SDLgameobject::draw();
}

void player::update()
{
  m_x-=1;
  m_currentframe=((SDL_GetTicks()/100)%6);
}