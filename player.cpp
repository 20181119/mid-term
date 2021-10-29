#include "player.h"
#include "gameobject.h"
void player::load(int x, int y, int width, int height, string textureID)
{
   gameobject::load(x, y, width, height, textureID);
}

void player::draw(SDL_Renderer* pRenderer)
{
  gameobject::draw(pRenderer);
}

void player::update()
{
  m_x-=1;
}