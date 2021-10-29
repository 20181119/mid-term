#pragma once
#include "SDL.h"
#include "texturemanager.h"
#include "gameobject.h"
#include "player.h"
#include <vector>
class game 
{

  private:
    game() {}
    static game* s_pinstance;

public:
~game() {}

static game* instance()
{
  if(s_pinstance==0)
 {
  s_pinstance=new game();
  return s_pinstance;
 }
return s_pinstance;
}


SDL_Renderer* getRenderer() const{return m_pRenderer;}

bool init(const char* title, int xpos, int ypos , int height, int width, int flags);
void render();
void update();
bool running();
void handleEvents();
void clean();

int m_currentframe;

vector<gameobject*> m_gameobjects;

private:
SDL_Window* m_pWindow;
SDL_Renderer* m_pRenderer;
bool m_bRunning;
};