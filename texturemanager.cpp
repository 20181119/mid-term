#include "texturemanager.h"
#include "SDL_image.h"

texturemanager* texturemanager::s_pinstance=0;
bool texturemanager::load(string fileName, string id, SDL_Renderer* pRenderer)
{
  SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
  if(pTempSurface==0)
  {   
    return false;
  }
  SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
      SDL_FreeSurface(pTempSurface);
  if(pTexture!=0)
  {
    m_textureMap[id] = pTexture;
    return true;
  }
    return false;
}

void texturemanager::draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer,SDL_RendererFlip flip)
{
    SDL_Rect m_srRect;
    SDL_Rect m_desRect;

    m_srRect.x=0;
    m_srRect.y=0;

    m_desRect.w=m_srRect.w=width;
    m_desRect.h=m_srRect.h=height;

    m_desRect.x=x;
    m_desRect.y=y;
    
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &m_srRect, &m_desRect, 0, 0, flip);
}

void texturemanager::drawframe(string id, int x, int y, int width, int height, int currentrow, int currentframe, SDL_Renderer* pRenderer,SDL_RendererFlip flip)
{
    SDL_Rect m_srRect;
    SDL_Rect m_desRect;

    m_srRect.x=width*currentframe;
    m_srRect.y=height*currentrow;

    m_desRect.w=m_srRect.w=width;
    m_desRect.h=m_srRect.h=height;

    m_desRect.x=x;
    m_desRect.y=y;
    
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &m_srRect, &m_desRect, 0, 0, flip);
}

