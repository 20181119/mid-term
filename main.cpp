#include <SDL.h>
#include "game.h"
#include <iostream>
game* g_game=0;
int main(int argc, char* args[])
{

  if(game::instance()->init("chapter1", 100, 100, 640,480, false))
  {
       while(game::instance()->running())
    {
      game::instance()->handleEvents();
      game::instance()->update();
      game::instance()->render();
      SDL_Delay(10);
    }
  }
  else
  {
     std::cout<<"game init failure"<<SDL_GetError()<<"\n";
    return -1;
  }
    
    
      game::instance()->clean();
    return 0;
}