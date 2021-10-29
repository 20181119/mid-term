#include <SDL.h>
#include "game.h"
game* g_game=0;
int main(int argc, char* args[])
{
    g_game=new game();
    g_game->init("classed SDL", 100, 100, 640,480, 0);
    
    while(g_game->running())
    {
      g_game->handleEvents();
      g_game->update();
      g_game->render();
    }
      g_game->clean();
    return 0;
}