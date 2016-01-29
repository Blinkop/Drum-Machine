#include "eventhandles.h"

bool CatchUpEvents(SDL_Window* window, GUI_elements* elements, SDL_Renderer* renderer, FramesChange* frames)
{
	char* filepath;
	Uint8 id;
	/*---bool variables---*/
	bool success = true;
	bool IQUIT = false;
	/*---Counters---*/
	Uint8 Button_pressed = NO_PRESS;
	/*---TIME---*/
	TimeLapse* time = (TimeLapse*)calloc(1, sizeof(TimeLapse));
	time->started = false;
	time->paused = false;
	time->OnRecord = false;
	t_list* recorded_time = NULL;
	PlayThread* playThread = NULL;
	SDL_Thread* ChannelThread = NULL;
	elements->bpm_control.bpm_value = 120;
	/*---Events---*/
	SDL_Event eventer;

	TimeThread* time_thread = (TimeThread*)malloc(sizeof(TimeThread));
	time_thread->elements = elements;
	time_thread->lapse = time;
	time_thread->renderer = renderer;
	SDL_EventState(SDL_DROPFILE, SDL_ENABLE);
	Mix_AllocateChannels(17);

	playThread = (PlayThread*)malloc(sizeof(PlayThread));
	playThread->elements = elements;
	playThread->lapse = time;
	playThread->list = &recorded_time;
	playThread->renderer = renderer;
	playThread->frames = frames;

	changeBPMTTF(renderer, elements);
	/*---Threads---*/
	SDL_Thread* timeThread = NULL;
	int threadStatus = -1;
	while (!IQUIT)
	{
		id = -1;		
		if (SDL_WaitEvent(&eventer))
		{
			if (eventer.type == SDL_QUIT)
				IQUIT = true;
			else if (eventer.type == SDL_KEYDOWN)
			{
				Uint64 padCode = keyTransform(eventer.key.keysym.sym);
				if (padCode <= 16)
				{
					if (time->OnRecord && time->started)
						push_time(&recorded_time,
							getSignTime(time, elements->bpm_control.bpm_value), padCode, elements->bpm_control.bpm_value);
					Mix_PlayChannel(padCode + 1, elements->pad[padCode].sound, 0);
					elements->pad[padCode].pad = updatePadButton(renderer, frames->padPressed);
				}
				else
				{
					changeBPM(elements, padCode);
					changeBPMTTF(renderer, elements);
				}
			}
			else if (eventer.type == SDL_KEYUP)
			{
				Uint8 padCode = keyTransform(eventer.key.keysym.sym);
				if (padCode <= 16)
				elements->pad[padCode].pad = updatePadButton(renderer, frames->pad);
			}
			else if (eventer.type == SDL_MOUSEBUTTONDOWN)
			{
				if (MouseOnButton(elements->RecordButton))
				{
					if (!time->OnRecord)
					{
						elements->RecordButton.frame = updatePadButton(renderer, frames->RecordPressed);
						time->OnRecord = true;
					}
					else
					{
						elements->RecordButton.frame = updatePadButton(renderer, frames->Record);
						time->OnRecord = false;
					}
				}
				else if (MouseOnButton(elements->PlayButton))
				{
					if (!time->started)
					{
						Play(time);
						PlayMap(&ChannelThread, playThread);
						timeThread = SDL_CreateThread(timerStart, "Timer", (void*)time_thread);
					}
					elements->PlayButton.frame = updatePadButton(renderer, frames->PlayPressed);
					Button_pressed = PLAY_BUTTON;
				}
				else if (MouseOnButton(elements->StopButton))
				{
					Stop(time);
					elements->StopButton.frame = updatePadButton(renderer, frames->StopPressed);
					SDL_WaitThread(ChannelThread, &threadStatus);
					SDL_WaitThread(timeThread, &threadStatus);
					ChannelThread = NULL;
					timeThread = NULL;
					Button_pressed = STOP_BUTTON;
				}
				else if (MouseOnButton(elements->ClearButton))
				{
					Clear(&recorded_time);
					elements->ClearButton.frame = updatePadButton(renderer, frames->ClearPressed);
					Button_pressed = CLEAR_BUTTON;
				}
				else if (MouseOnButton(elements->ToStartButton))
				{
					Stop(time);
					SDL_WaitThread(ChannelThread, &threadStatus);
					SDL_WaitThread(timeThread, &threadStatus);
					ChannelThread = NULL;
					timeThread = NULL;
					Play(time);
					PlayMap(&ChannelThread, playThread);
					timeThread = SDL_CreateThread(timerStart, "Timer", (void*)time_thread);
					elements->ToStartButton.frame = updatePadButton(renderer, frames->ToStartPressed);
					Button_pressed = TO_START_BUTTON;
				}
				else if (MouseOnButton(elements->QuantizeButton))
				{
					Quantize(recorded_time);
					elements->QuantizeButton.frame = updatePadButton(renderer, frames->QuantizePressed);
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
					printf("Load Error: %s\n", Mix_GetError()); //STDERR
				SDL_free(filepath);
			}
			/*---TEST---*/
			SDL_RenderClear(renderer);
			UpdateScreen(renderer, elements);
			/*---TEST END---*/
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
void Unpress(Uint8 button, FramesChange* frames, GUI_elements* elements, SDL_Renderer* renderer) //FUNCTION ARRAY
{
	if (button == PLAY_BUTTON)
	{
		elements->PlayButton.frame = updatePadButton(renderer, frames->Play);
	}
	else if (button == STOP_BUTTON)
	{
		elements->StopButton.frame = updatePadButton(renderer, frames->Stop);
	}
	else if (button == CLEAR_BUTTON)
	{
		elements->ClearButton.frame = updatePadButton(renderer, frames->Clear);
	}
	else if (button == TO_START_BUTTON)
	{
		elements->ToStartButton.frame = updatePadButton(renderer, frames->ToStart);
	}
	else if (button == QUANTIZE_BUTTON)
	{
		elements->QuantizeButton.frame = updatePadButton(renderer, frames->Quantize);
	}
}
Uint64 keyTransform(SDL_Keycode code)
{
	Uint64 padCode;
	switch (code)
	{
	case SDLK_1:
	case SDLK_2:
	case SDLK_3:
	case SDLK_4:
		padCode = code - 49;
		break;
	case SDLK_q:
		padCode = 4;
		break;
	case SDLK_w:
		padCode = 5;
		break;
	case SDLK_e:
		padCode = 6;
		break;
	case SDLK_r:
		padCode = 7;
		break;
	case SDLK_a:
		padCode = 8;
		break;
	case SDLK_s:
		padCode = 9;
		break;
	case SDLK_d:
		padCode = 10;
		break;
	case SDLK_f:
		padCode = 11;
		break;
	case SDLK_z:
		padCode = 12;
		break;
	case SDLK_x:
		padCode = 13;
		break;
	case SDLK_c:
		padCode = 14;
		break;
	case SDLK_v:
		padCode = 15;
		break;
	default:
		padCode = code;
	}
	return padCode;
}
void changeBPM(GUI_elements* elements, SDL_Keycode code)
{
	if (code == SDLK_UP)
	{
		if (elements->bpm_control.bpm_value < 299)
			elements->bpm_control.bpm_value++;
	}
	else if (code == SDLK_DOWN)
	{
		if (elements->bpm_control.bpm_value > 1)
			elements->bpm_control.bpm_value--;
	}
}