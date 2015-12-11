#include "windowoperations.h"

bool DMinitialize(SDL_Window** window, SDL_Surface** surface, GUI_elements* elements)
{
	bool success = true;
	SDL_Texture* texture = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to load Drum Machine: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		*window = SDL_CreateWindow("Drum Machine", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (*window == NULL)
		{
			printf("Failed to load Drum Machine: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			*surface = SDL_GetWindowSurface(*window);
			texture = loadTexture("Frames\\Texture.png", *window);
			loadImageSource(elements);
			BlitGUI(elements, *surface);
		}
	}
	return success;
}
bool loadImageSource(GUI_elements* elements)
{
	bool success = true;
	elements->padsFrame = SDL_LoadBMP("Frames\\PadsFrame.bmp");
	elements->pad_1 = SDL_LoadBMP("Frames\\Pad.bmp");
	return success;
}
void DMclose(SDL_Window** window, GUI_elements** elements)
{
	SDL_DestroyWindow(*window);
	SDL_Quit();
}
SDL_Surface* updatePadButton(Uint8 status, SDL_Surface** surface)
{
	if (status == 0)
	{
		SDL_FreeSurface(*surface);
		*surface = SDL_LoadBMP("Frames\\Pad.bmp");
		if (*surface == NULL) printf("Frame error: %s", SDL_GetError());
	}
	else if (status == 1)
	{
		SDL_FreeSurface(*surface);
		*surface = SDL_LoadBMP("Frames\\PadPressed.bmp");
		if (*surface == NULL) printf("Frame error: %s", SDL_GetError());
	}
	else puts("Wrong state");
	return *surface;
}
SDL_Texture* loadTexture(char* const path, SDL_Window* const window)
{
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Texture* texture = NULL;
	SDL_Surface* textureSurface = IMG_Load(path);
	if (renderer == NULL)
		printf("Texture error: %s", SDL_GetError());
	else
	{
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
			printf("Texture error: %s", SDL_GetError());
		if (textureSurface == NULL)
			printf("Texture error: %s", SDL_GetError());
		else
		{
			texture = SDL_CreateTextureFromSurface(renderer, textureSurface);
			if (texture == NULL)
				printf("Texture error: %s", SDL_GetError());
			SDL_FreeSurface(textureSurface);
		}
	}
	return texture;
}
void BlitGUI(GUI_elements* elements, SDL_Surface* const screenSurface)
{
	SDL_BlitSurface(elements->pad_1, NULL, screenSurface, NULL);
	SDL_BlitSurface(elements->padsFrame, NULL, screenSurface, NULL);
}