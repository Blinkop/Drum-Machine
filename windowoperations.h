#ifndef _WINDOWOPERATIONS_H_
#define _WINDOWOPERATIONS_H_

#include "machineelements.h"

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 700

bool DMinitialize(SDL_Window**, GUI_elements*, SDL_Renderer**, FramesChange*);
bool loadImageSource(GUI_elements*, SDL_Renderer*, FramesChange*);

void DMclose(SDL_Window**, GUI_elements**);
void BlitGUI(GUI_elements*, SDL_Renderer*);

SDL_Texture* updatePadButton(Uint8, SDL_Texture*, SDL_Renderer*, FramesChange*);
SDL_Texture* loadTexture(char* const, SDL_Renderer*);

SDL_Rect CreateRect(int, int, int, int);

#endif