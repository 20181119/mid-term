#include "game.h"

bool game::init(const char *title, int xpos, int ypos, int width, int height, int flags)
{
      if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
  {
     m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
      if (m_pWindow != 0)
    {
       m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
          if (m_pRenderer != 0)
        {
          SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
        } 
     else 
     {
       return false;
     }
    } 
    else
    {
        return false; 
    }

  } 
  
  else
   {
   return false; 
   }

   
    SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    SDL_QueryTexture(m_pTexture, NULL, NULL, &m_srRect.w, &m_srRect.h);

    m_desRect.w=m_srRect.w;
    m_desRect.h=m_srRect.h;

    m_desRect.x=m_srRect.x=0;
    m_desRect.y=m_srRect.y=0;
    

   m_bRunning = true;
   return true;
}

void game::update()
{

}

void game::render()
{
  SDL_RenderClear(m_pRenderer);
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srRect, &m_desRect);
  SDL_RenderPresent(m_pRenderer);
}
bool game::running()
{
  return m_bRunning;
}

void game::handleEvents()
{
SDL_Event event;
if (SDL_PollEvent(&event)) 
{
switch (event.type) 
  {
    case SDL_QUIT:
    m_bRunning = false;
    break;
    default:
    break;
  } 
}

}
void game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}