#include "game.h"
#include "SDL_image.h"
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
          SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
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

    m_texturemanager.load("Assets/animate-alpha.png","animate", m_pRenderer);


   m_bRunning = true;
   return true;
}

void game::update()
{
    m_currentframe=((SDL_GetTicks()/100)%6);
}

void game::render()
{
  SDL_RenderClear(m_pRenderer);
  m_texturemanager.draw("animate", 0, 0, 128, 82, m_pRenderer);
  m_texturemanager.drawframe("animate", 100, 100, 128, 82, 0, m_currentframe, m_pRenderer);
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