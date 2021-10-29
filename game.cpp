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

    if(!texturemanager::instance()->load("Assets/animate-alpha.png","animate", m_pRenderer))
    {
      return false; 
    }


  gameobject* m_go=new gameobject();
  gameobject* m_player=new player();

m_go->load(100, 100, 128, 82, "animate");
m_player->load(300, 300, 128, 82, "animate");

m_gameobjects.push_back(m_go);
m_gameobjects.push_back(m_player);



   m_bRunning = true;
   return true;
}

void game::update()
{
   for(int i=0;i<m_gameobjects.size();i++)
   {
        m_gameobjects[i]->update();
   }
}

void game::render()
{
  SDL_RenderClear(m_pRenderer);
   
  for(int i=0;i<m_gameobjects.size();i++)
   {
       m_gameobjects[i]->draw(m_pRenderer);
   }

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