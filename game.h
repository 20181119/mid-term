#pragma once
#include "SDL.h"
#include "texturemanager.h"

class game 
{
public:
game() {}
~game() {}

bool init(const char* title, int xpos, int ypos , int height, int width, int flags);
void render();
void update();
bool running();
void handleEvents();
void clean();

int m_currentframe;

private:
SDL_Window* m_pWindow;
SDL_Renderer* m_pRenderer;
bool m_bRunning;
};