#ifndef _WINDOWOPERATIONS_H_
#define _WINDOWOPERATIONS_H_

#include "machineelements.h"

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 600

bool DMinitialize(SDL_Window**, SDL_Surface**, GUI_elements*);
bool loadImageSource(GUI_elements*);
void DMclose(SDL_Window**, GUI_elements**);
SDL_Surface* updatePadButton(Uint8, SDL_Surface*);
SDL_Texture* loadTexture(char* const, SDL_Window* const);
void BlitGUI(GUI_elements*, SDL_Surface* const);

#endif