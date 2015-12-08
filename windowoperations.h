#ifndef _WINDOWOPERATIONS_H_
#define _WINDOWOPERATIONS_H_

#include <SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

bool DMinitialize(SDL_Window*);
bool loadImageSource();
void DMclose();

#endif