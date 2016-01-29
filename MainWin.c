#include "eventhandles.h"

int main(int argc, char** argv)
{
	/*---Global window and renderer---*/
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	/*---Experemental---*/
	SDL_Surface* current = NULL;
	bool quitFlag = false;
	/*---Additional elements---*/
	GUI_elements* gui_elements = (GUI_elements*)malloc(sizeof(GUI_elements));
	FramesChange* frames = (FramesChange*)malloc(sizeof(FramesChange));
	/*---Base variables---*/
	if (!DMinitialize(&window, gui_elements, &renderer, frames))
	{
		fputs("Failed to initialize Drum Machine", stderr);
	}
	else
	{
		SDL_UpdateWindowSurface(window);
		CatchUpEvents(window, gui_elements, renderer, frames);
	}
	DMclose(&window, &gui_elements);
	return 0;
}