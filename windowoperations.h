#ifndef _WINDOWOPERATIONS_H_
#define _WINDOWOPERATIONS_H_

#include "machinefunctional.h"

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 700

bool DMinitialize(SDL_Window**, GUI_elements*, SDL_Renderer**, FramesChange*);
bool loadImageSource(GUI_elements*, SDL_Renderer*, FramesChange*);

void DMclose(SDL_Window**, GUI_elements**);
void BlitGUI(GUI_elements*, SDL_Renderer*);
void NewTextureOnRender(SDL_Renderer*, SDL_Texture*, SDL_Texture*, SDL_Rect);
void updateTimeTTF(SDL_Renderer*, GUI_elements*, TimeLapse*);

SDL_Texture* updatePadButton(SDL_Texture*, SDL_Renderer*, SDL_Texture*);
SDL_Texture* loadTexture(char* const, SDL_Renderer*);

SDL_Rect CreateRect(int, int, int, int);
SDL_Color CreateColor(Uint8, Uint8, Uint8, Uint8);

#endif