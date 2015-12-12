#include "windowoperations.h"

bool CatchUpEvents(SDL_Window* window, GUI_elements* elements, SDL_Renderer* renderer, FramesChange* frames)
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
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_1.pad, renderer, frames), 0, &elements->pad_1.rect);
					break;
				case SDLK_2:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_2.pad, renderer, frames), 0, &elements->pad_2.rect);
					break;
				case SDLK_3:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_3.pad, renderer, frames), 0, &elements->pad_3.rect);
					break;
				case SDLK_4:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_4.pad, renderer, frames), 0, &elements->pad_4.rect);
					break;
				case SDLK_q:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_5.pad, renderer, frames), 0, &elements->pad_5.rect);
					break;
				case SDLK_w:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_6.pad, renderer, frames), 0, &elements->pad_6.rect);
					break;
				case SDLK_e:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_7.pad, renderer, frames), 0, &elements->pad_7.rect);
					break;
				case SDLK_r:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_8.pad, renderer, frames), 0, &elements->pad_8.rect);
					break;
				case SDLK_a:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_9.pad, renderer, frames), 0, &elements->pad_9.rect);
					break;
				case SDLK_s:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_10.pad, renderer, frames), 0, &elements->pad_10.rect);
					break;
				case SDLK_d:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_11.pad, renderer, frames), 0, &elements->pad_11.rect);
					break;
				case SDLK_f:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_12.pad, renderer, frames), 0, &elements->pad_12.rect);
					break;
				case SDLK_z:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_13.pad, renderer, frames), 0, &elements->pad_13.rect);
					break;
				case SDLK_x:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_14.pad, renderer, frames), 0, &elements->pad_14.rect);
					break;
				case SDLK_c:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_15.pad, renderer, frames), 0, &elements->pad_15.rect);
					break;
				case SDLK_v:
					SDL_RenderCopy(renderer,
						updatePadButton(PRESSED, elements->pad_16.pad, renderer, frames), 0, &elements->pad_16.rect);
					break;
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
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_1.pad, renderer, frames), 0, &elements->pad_1.rect);
					break;
				case SDLK_2:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED,elements->pad_2.pad, renderer, frames), 0, &elements->pad_2.rect);
					break;
				case SDLK_3:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_3.pad, renderer, frames), 0, &elements->pad_3.rect);
					break;
				case SDLK_4:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_4.pad, renderer, frames), 0, &elements->pad_4.rect);
					break;
				case SDLK_q:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_5.pad, renderer, frames), 0, &elements->pad_5.rect);
					break;
				case SDLK_w:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_6.pad, renderer, frames), 0, &elements->pad_6.rect);
					break;
				case SDLK_e:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_7.pad, renderer, frames), 0, &elements->pad_7.rect);
					break;
				case SDLK_r:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_8.pad, renderer, frames), 0, &elements->pad_8.rect);
					break;
				case SDLK_a:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_9.pad, renderer, frames), 0, &elements->pad_9.rect);
					break;
				case SDLK_s:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_10.pad, renderer, frames), 0, &elements->pad_10.rect);
					break;
				case SDLK_d:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_11.pad, renderer, frames), 0, &elements->pad_11.rect);
					break;
				case SDLK_f:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_12.pad, renderer, frames), 0, &elements->pad_12.rect);
					break;
				case SDLK_z:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_13.pad, renderer, frames), 0, &elements->pad_13.rect);
					break;
				case SDLK_x:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_14.pad, renderer, frames), 0, &elements->pad_14.rect);
					break;
				case SDLK_c:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_15.pad, renderer, frames), 0, &elements->pad_15.rect);
					break;
				case SDLK_v:
					SDL_RenderCopy(renderer,
						updatePadButton(UNPRESSED, elements->pad_16.pad, renderer, frames), 0, &elements->pad_16.rect);
					break;
				default:
					puts("kek");
					break;
				}
			}
			SDL_RenderPresent(renderer);
		}
	}
	return success;
}