#ifndef _WINDOWOPERATIONS_H_
#define _WINDOWOPERATIONS_H_

#include "machineelements.h"
#include <SDL_ttf.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 700

bool DMinitialize(SDL_Window**, GUI_elements*, SDL_Renderer**, FramesChange*);
bool loadImageSource(GUI_elements*, SDL_Renderer*, FramesChange*);

void DMclose(SDL_Window**, GUI_elements**);
void BlitGUI(GUI_elements*, SDL_Renderer*);
void NewTextureOnRender(SDL_Renderer*, SDL_Texture*, SDL_Texture*, SDL_Rect);

SDL_Texture* updatePadButton(SDL_Texture*, SDL_Renderer*, SDL_Texture*);
SDL_Texture* loadTexture(char* const, SDL_Renderer*);

SDL_Rect CreateRect(int, int, int, int);

#endif