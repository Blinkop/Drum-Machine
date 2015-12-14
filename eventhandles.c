#include "eventhandles.h"
#include "machinefunctional.h"
#include "timing.h"

bool CatchUpEvents(SDL_Window* window, GUI_elements* elements, SDL_Renderer* renderer, FramesChange* frames)
{
	/*---bool variables---*/
	bool success = true;
	bool IQUIT = false;
	bool OnRecord = false;
	/*---Counters---*/
	Uint8 Button_pressed = NO_PRESS;
	/*---TIME---*/
	TimeLapse time;
	time.started = false;
	time.paused = false;
	/*---Events---*/
	SDL_Event eventer;
	while (!IQUIT)
	{
		while (SDL_PollEvent(&eventer) != 0)
		{
			if (eventer.type == SDL_QUIT)
				IQUIT = true;
			else if (eventer.type == SDL_MOUSEBUTTONDOWN)
			{
				if (MouseOnButton(elements->RecordButton))
				{
					if (!OnRecord)
					{
						NewTextureOnRender(renderer, elements->RecordButton.frame,
							frames->RecordPressed, elements->RecordButton.rect);
						OnRecord = true;
					}
					else
					{
						NewTextureOnRender(renderer, elements->RecordButton.frame,
							frames->Record, elements->RecordButton.rect);
						OnRecord = false;
					}
				}
				else if (MouseOnButton(elements->PlayButton))
				{
					NewTextureOnRender(renderer, elements->PlayButton.frame,
						frames->PlayPressed, elements->PlayButton.rect);
					Button_pressed = PLAY_BUTTON;
				}
				else if (MouseOnButton(elements->StopButton))
				{
					NewTextureOnRender(renderer, elements->StopButton.frame,
						frames->StopPressed, elements->StopButton.rect);
					Button_pressed = STOP_BUTTON;
				}
				else if (MouseOnButton(elements->ClearButton))
				{
					NewTextureOnRender(renderer, elements->ClearButton.frame,
						frames->ClearPressed, elements->ClearButton.rect);
					Button_pressed = CLEAR_BUTTON;
				}
				else if (MouseOnButton(elements->ToStartButton))
				{
					NewTextureOnRender(renderer, elements->ToStartButton.frame,
						frames->ToStartPressed, elements->ToStartButton.rect);
					Button_pressed = TO_START_BUTTON;
				}
				else if (MouseOnButton(elements->QuantizeButton))
				{
					NewTextureOnRender(renderer, elements->QuantizeButton.frame,
						frames->QuantizePressed, elements->QuantizeButton.rect);
					Button_pressed = QUANTIZE_BUTTON;
				}
			}
			else if (eventer.type == SDL_MOUSEBUTTONUP)
			{
				Unpress(Button_pressed, frames, elements, renderer);
				Button_pressed = NO_PRESS;
			}
			else if (eventer.type == SDL_KEYDOWN)
			{
				switch (eventer.key.keysym.sym)
				{
				case SDLK_1:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_1.pad, renderer, frames->padPressed), 0, &elements->pad_1.rect);
					break;
				case SDLK_2:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_2.pad, renderer, frames->padPressed), 0, &elements->pad_2.rect);
					break;
				case SDLK_3:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_3.pad, renderer, frames->padPressed), 0, &elements->pad_3.rect);
					break;
				case SDLK_4:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_4.pad, renderer, frames->padPressed), 0, &elements->pad_4.rect);
					break;
				case SDLK_q:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_5.pad, renderer, frames->padPressed), 0, &elements->pad_5.rect);
					break;
				case SDLK_w:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_6.pad, renderer, frames->padPressed), 0, &elements->pad_6.rect);
					break;
				case SDLK_e:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_7.pad, renderer, frames->padPressed), 0, &elements->pad_7.rect);
					break;
				case SDLK_r:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_8.pad, renderer, frames->padPressed), 0, &elements->pad_8.rect);
					break;
				case SDLK_a:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_9.pad, renderer, frames->padPressed), 0, &elements->pad_9.rect);
					break;
				case SDLK_s:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_10.pad, renderer, frames->padPressed), 0, &elements->pad_10.rect);
					break;
				case SDLK_d:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_11.pad, renderer, frames->padPressed), 0, &elements->pad_11.rect);
					break;
				case SDLK_f:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_12.pad, renderer, frames->padPressed), 0, &elements->pad_12.rect);
					break;
				case SDLK_z:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_13.pad, renderer, frames->padPressed), 0, &elements->pad_13.rect);
					break;
				case SDLK_x:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_14.pad, renderer, frames->padPressed), 0, &elements->pad_14.rect);
					break;
				case SDLK_c:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_15.pad, renderer, frames->padPressed), 0, &elements->pad_15.rect);
					break;
				case SDLK_v:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_16.pad, renderer, frames->padPressed), 0, &elements->pad_16.rect);
					break;
				default:
					break;
				}
			}
			else if (eventer.type == SDL_KEYUP)
			{
				switch (eventer.key.keysym.sym)
				{
				case SDLK_1:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_1.pad, renderer, frames->pad), 0, &elements->pad_1.rect);
					break;
				case SDLK_2:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_2.pad, renderer, frames->pad), 0, &elements->pad_2.rect);
					break;
				case SDLK_3:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_3.pad, renderer, frames->pad), 0, &elements->pad_3.rect);
					break;
				case SDLK_4:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_4.pad, renderer, frames->pad), 0, &elements->pad_4.rect);
					break;
				case SDLK_q:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_5.pad, renderer, frames->pad), 0, &elements->pad_5.rect);
					break;
				case SDLK_w:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_6.pad, renderer, frames->pad), 0, &elements->pad_6.rect);
					break;
				case SDLK_e:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_7.pad, renderer, frames->pad), 0, &elements->pad_7.rect);
					break;
				case SDLK_r:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_8.pad, renderer, frames->pad), 0, &elements->pad_8.rect);
					break;
				case SDLK_a:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_9.pad, renderer, frames->pad), 0, &elements->pad_9.rect);
					break;
				case SDLK_s:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_10.pad, renderer, frames->pad), 0, &elements->pad_10.rect);
					break;
				case SDLK_d:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_11.pad, renderer, frames->pad), 0, &elements->pad_11.rect);
					break;
				case SDLK_f:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_12.pad, renderer, frames->pad), 0, &elements->pad_12.rect);
					break;
				case SDLK_z:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_13.pad, renderer, frames->pad), 0, &elements->pad_13.rect);
					break;
				case SDLK_x:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_14.pad, renderer, frames->pad), 0, &elements->pad_14.rect);
					break;
				case SDLK_c:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_15.pad, renderer, frames->pad), 0, &elements->pad_15.rect);
					break;
				case SDLK_v:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad_16.pad, renderer, frames->pad), 0, &elements->pad_16.rect);
					break;
				default:
					break;
				}
			}
			SDL_RenderPresent(renderer);
		}
	}
	return success;
}
bool MouseOnButton(DM_Button button)
{
	int x, y;
	bool inside = true;
	SDL_GetMouseState(&x, &y);
	if (x < button.rect.x) inside = false;
	else if (x >(button.rect.x + button.rect.w)) inside = false;
	else if (y < button.rect.y) inside = false;
	else if (y > (button.rect.y + button.rect.h)) inside = false;

	return inside;
}
void Unpress(Uint8 button, FramesChange* frames, GUI_elements* elements, SDL_Renderer* renderer)
{
	if (button == PLAY_BUTTON)
	{
		NewTextureOnRender(renderer, elements->PlayButton.frame,
			frames->Play, elements->PlayButton.rect);
	}
	else if (button == STOP_BUTTON)
	{
		NewTextureOnRender(renderer, elements->StopButton.frame,
			frames->Stop, elements->StopButton.rect);
	}
	else if (button == CLEAR_BUTTON)
	{
		NewTextureOnRender(renderer, elements->ClearButton.frame,
			frames->Clear, elements->ClearButton.rect);
	}
	else if (button == TO_START_BUTTON)
	{
		NewTextureOnRender(renderer, elements->ToStartButton.frame,
			frames->ToStart, elements->ToStartButton.rect);
	}
	else if (button == QUANTIZE_BUTTON)
	{
		NewTextureOnRender(renderer, elements->QuantizeButton.frame,
			frames->Quantize, elements->QuantizeButton.rect);
	}
}