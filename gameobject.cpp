#include "gameobject.h"
#include "texturemanager.h"
void gameobject::load(int x, int y, int width, int height, string textureID)
{
m_x=x;
m_y=y;
m_width=width;
m_height=height;
m_textureID=textureID;

m_currentrow=0;
m_currentframe=0;
}

void gameobject::draw(SDL_Renderer* pRenderer)
{
texturemanager::instance()->drawframe(m_textureID, 
m_x,
m_y,
m_width,
m_height,
m_currentrow,
m_currentframe, pRenderer);
}

void gameobject::update()
{
m_x+=1;
}