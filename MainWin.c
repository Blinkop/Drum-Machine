#include "windowoperations.h"

int main(int argc, char** argv)
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Error: %s", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("KEK", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		screenSurface = SDL_GetWindowSurface(window);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x24, 0x34, 0x0F));
		SDL_UpdateWindowSurface(window);
		SDL_Delay(2000);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	
	return 0;
}