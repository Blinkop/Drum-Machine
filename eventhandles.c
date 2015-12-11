#include "windowoperations.h"

bool CatchUpEvents(SDL_Window* window, SDL_Surface* screenSurface, GUI_elements* elements)
{
	/*---bool variables---*/
	bool success = true;
	bool IQUIT = false;
	/*---Events---*/
	SDL_Event eventer;
	SDL_KeyboardEvent kevent;
	while (!IQUIT)
	{
		while (SDL_PollEvent(&eventer) != 0)
		{
			if (eventer.type == SDL_QUIT)
				IQUIT = true;
			else if (eventer.type == SDL_KEYDOWN)
			{
				switch (eventer.key.keysym.sym)
				{
				case SDLK_1:
					SDL_BlitSurface(updatePadButton(PRESSED, &elements->pad_1), NULL, screenSurface, NULL);
					SDL_UpdateWindowSurface(window);
				default:
					puts("kek");
					break;
				}
			}
			else if (eventer.type == SDL_KEYUP)
			{
				switch (eventer.key.keysym.sym)
				{
				case SDLK_1:
					SDL_BlitSurface(updatePadButton(UNPRESSED, &elements->pad_1), NULL, screenSurface, NULL);
					SDL_UpdateWindowSurface(window);
				default:
					puts("kek");
					break;
				}
			}
		}
	}
	return success;
}