#include "eventhandles.h"
#include "machinefunctional.h"
#include "timing.h"
#include "timelist.h"

bool CatchUpEvents(SDL_Window* window, GUI_elements* elements, SDL_Renderer* renderer, FramesChange* frames)
{
	char* filepath;
	Uint8 id;
	SDL_Color bar_color = { 0, 0, 0, 0 };
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

	SDL_EventState(SDL_DROPFILE, SDL_ENABLE);
	Mix_AllocateChannels(17);
	while (!IQUIT)
	{
		id = -1;
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
						updatePadButton(elements->pad[0].pad, renderer, frames->padPressed), 0, &elements->pad[0].rect);
					Mix_PlayChannel(1, elements->pad[0].sound, 0);
					break;
				case SDLK_2:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[1].pad, renderer, frames->padPressed), 0, &elements->pad[1].rect);
					Mix_PlayChannel(2, elements->pad[1].sound, 0);
					break;
				case SDLK_3:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[2].pad, renderer, frames->padPressed), 0, &elements->pad[2].rect);
					Mix_PlayChannel(3, elements->pad[2].sound, 0);
					break;
				case SDLK_4:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[3].pad, renderer, frames->padPressed), 0, &elements->pad[3].rect);
					Mix_PlayChannel(4, elements->pad[3].sound, 0);
					break;
				case SDLK_q:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[4].pad, renderer, frames->padPressed), 0, &elements->pad[4].rect);
					Mix_PlayChannel(5, elements->pad[4].sound, 0);
					break;
				case SDLK_w:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[5].pad, renderer, frames->padPressed), 0, &elements->pad[5].rect);
					Mix_PlayChannel(6, elements->pad[5].sound, 0);
					break;
				case SDLK_e:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[6].pad, renderer, frames->padPressed), 0, &elements->pad[6].rect);
					Mix_PlayChannel(7, elements->pad[6].sound, 0);
					break;
				case SDLK_r:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[7].pad, renderer, frames->padPressed), 0, &elements->pad[7].rect);
					Mix_PlayChannel(8, elements->pad[7].sound, 0);
					break;
				case SDLK_a:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[8].pad, renderer, frames->padPressed), 0, &elements->pad[8].rect);
					Mix_PlayChannel(9, elements->pad[8].sound, 0);
					break;
				case SDLK_s:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[9].pad, renderer, frames->padPressed), 0, &elements->pad[9].rect);
					Mix_PlayChannel(10, elements->pad[9].sound, 0);
					break;
				case SDLK_d:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[10].pad, renderer, frames->padPressed), 0, &elements->pad[10].rect);
					Mix_PlayChannel(11, elements->pad[10].sound, 0);
					break;
				case SDLK_f:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[11].pad, renderer, frames->padPressed), 0, &elements->pad[11].rect);
					Mix_PlayChannel(12, elements->pad[11].sound, 0);
					break;
				case SDLK_z:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[12].pad, renderer, frames->padPressed), 0, &elements->pad[12].rect);
					Mix_PlayChannel(13, elements->pad[12].sound, 0);
					break;
				case SDLK_x:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[13].pad, renderer, frames->padPressed), 0, &elements->pad[13].rect);
					Mix_PlayChannel(14, elements->pad[13].sound, 0);
					break;
				case SDLK_c:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[14].pad, renderer, frames->padPressed), 0, &elements->pad[14].rect);
					Mix_PlayChannel(15, elements->pad[14].sound, 0);
					break;
				case SDLK_v:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[15].pad, renderer, frames->padPressed), 0, &elements->pad[15].rect);
					Mix_PlayChannel(16, elements->pad[15].sound, 0);
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
						updatePadButton(elements->pad[0].pad, renderer, frames->pad), 0, &elements->pad[0].rect);
					break;
				case SDLK_2:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[1].pad, renderer, frames->pad), 0, &elements->pad[1].rect);
					break;
				case SDLK_3:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[2].pad, renderer, frames->pad), 0, &elements->pad[2].rect);
					break;
				case SDLK_4:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[3].pad, renderer, frames->pad), 0, &elements->pad[3].rect);
					break;
				case SDLK_q:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[4].pad, renderer, frames->pad), 0, &elements->pad[4].rect);
					break;
				case SDLK_w:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[5].pad, renderer, frames->pad), 0, &elements->pad[5].rect);
					break;
				case SDLK_e:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[6].pad, renderer, frames->pad), 0, &elements->pad[6].rect);
					break;
				case SDLK_r:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[7].pad, renderer, frames->pad), 0, &elements->pad[7].rect);
					break;
				case SDLK_a:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[8].pad, renderer, frames->pad), 0, &elements->pad[8].rect);
					break;
				case SDLK_s:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[9].pad, renderer, frames->pad), 0, &elements->pad[9].rect);
					break;
				case SDLK_d:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[10].pad, renderer, frames->pad), 0, &elements->pad[10].rect);
					break;
				case SDLK_f:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[11].pad, renderer, frames->pad), 0, &elements->pad[11].rect);
					break;
				case SDLK_z:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[12].pad, renderer, frames->pad), 0, &elements->pad[12].rect);
					break;
				case SDLK_x:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[13].pad, renderer, frames->pad), 0, &elements->pad[13].rect);
					break;
				case SDLK_c:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[14].pad, renderer, frames->pad), 0, &elements->pad[14].rect);
					break;
				case SDLK_v:
					SDL_RenderCopy(renderer,
						updatePadButton(elements->pad[15].pad, renderer, frames->pad), 0, &elements->pad[15].rect);
					break;
				default:
					break;
				}
			}
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
			else if (eventer.type == SDL_DROPFILE)
			{
				filepath = eventer.drop.file;
				for (int i = 0; i < 16; i++)
				{
					if (MouseOnPad(elements->pad[i]))
					{
						Mix_FreeChunk(elements->pad[i].sound);
						elements->pad[i].sound = Mix_LoadWAV(filepath);
						id = i;
						break;
					}
				}
				if (elements->pad[id].sound == NULL)
					printf("Load Error: %s\n", Mix_GetError());
				SDL_free(filepath);
			}
			SDL_RenderPresent(renderer);
		}
	}
	return success;
}
bool MouseOnButton(DM_Button button)
{
	return MouseOnRect(button.rect);
}
bool MouseOnPad(DM_channel channel)
{
	return MouseOnRect(channel.rect);
}
bool MouseOnRect(SDL_Rect rect)
{
	int x, y;
	bool inside = true;
	SDL_GetMouseState(&x, &y);
	if (x < rect.x) inside = false;
	else if (x >(rect.x + rect.w)) inside = false;
	else if (y < rect.y) inside = false;
	else if (y >(rect.y + rect.h)) inside = false;

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