#pragma once
#include "SDL.h"
#include <map>
#include <string>
using namespace std;
class texturemanager
{
  private:
    texturemanager(){}
    static texturemanager* s_pinstance;
  public:
  static texturemanager* instance()
   {
     if(s_pinstance==0)
     s_pinstance=new texturemanager();
     return s_pinstance;
   }
    
    ~texturemanager(){}

    bool load(string fileName, string id, SDL_Renderer* pRenderer);

    void draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer,SDL_RendererFlip flip = SDL_FLIP_NONE); 

    void drawframe(string id, int x, int y, int width, int height, int currentrow, int currentframe, SDL_Renderer* pRenderer,SDL_RendererFlip flip = SDL_FLIP_NONE);
    
  private:
    map<string, SDL_Texture*> m_textureMap;
};