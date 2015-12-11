#include "eventhandles.h"
#include <SDL_mixer.h>

int main(int argc, char** argv)
{
	/*---Global window and surface---*/
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	/*---Experemental---*/
	SDL_Surface* current = NULL;
	bool quitFlag = false;
	/*---Additional surfaces---*/
	GUI_elements* gui_elements = malloc(sizeof(GUI_elements));
	/*---Base variables---*/
	SDL_Surface* KeyPressedSurface[KEYS_TOTAL];
	if (!DMinitialize(&window, &screenSurface, gui_elements))
	{
		puts("Failed to initialize Drum Machine");
	}
	else
	{
		SDL_UpdateWindowSurface(window);
		CatchUpEvents(window, screenSurface, gui_elements);
	}
	DMclose(&window, &gui_elements);
	
	return 0;
}