#include "threadmanager.h"

int KappaForPress(PressDelay* data)
{
	/*KappaPride*/
	SDL_Delay(500);
	data->elements->pad[data->id].pad = updatePadButton(data->renderer, data->frames->pad);
}
int timerStart(TimeThread* data)
{
	Uint8 beat = 0;
	Uint8 step = 0;
	Uint8 tick = 0;
	while (data->lapse->started)
	{
		getSignalTime(data->lapse, data->elements->bpm_control.bpm_value);
		if (/*data->lapse->tick != tick || */data->lapse->step != step || data->lapse->beat != beat)
		{
			updateTimeTTF(data->renderer, data->elements, data->lapse);
		}
		beat = data->lapse->beat;
		step = data->lapse->step;
		tick = data->lapse->tick;
	}
	return 0;
}
int PlayChannel(PlayThread* data)
{
	t_list* top_time = *(data->list);
	t_list* current_time = top_time;
	t_list* prev_top = top_time;
	Uint32 prev_time = 0;
	while (data->lapse->started)
	{
		Uint32 topCycleTime = getCurrentTime(data->lapse, data->elements->bpm_control.bpm_value);
		top_time = *(data->list);
		if (top_time != NULL)
		{
			if (prev_top != top_time && current_time == NULL)
			{
				current_time = top_time;
			}
			else
			{
				Uint8 padCode = current_time->id;
				Uint32 time = timeTransform(current_time->time, data->elements->bpm_control.bpm_value);
				if (time == 0)
				{
					Mix_PlayChannel(padCode + 1, data->elements->pad[padCode].sound, 0);
					puts("Sound Played!");
					data->elements->pad[padCode].pad = updatePadButton(data->renderer, data->frames->padPressed);
				}
				else
				{
					Uint32 bottomCycleTime = getCurrentTime(data->lapse, data->elements->bpm_control.bpm_value);
					SDL_Delay(time - (bottomCycleTime - topCycleTime) - prev_time);
					Mix_PlayChannel(padCode + 1, data->elements->pad[padCode].sound, 0);
					puts("Sound Played!");
					data->elements->pad[padCode].pad = updatePadButton(data->renderer, data->frames->padPressed);
				}
			}
			/*DELAY*/
			data->elements->pad[current_time->id].pad = updatePadButton(data->renderer, data->frames->pad);
			/*PressDelay delay = { current_time->id, data->renderer, data->elements, data->frames };
			SDL_CreateThread(KappaForPress, "PogChamp", (void*)&delay);*/
			prev_time = timeTransform(current_time->time, data->elements->bpm_control.bpm_value);
			current_time = current_time->next;
			if (current_time == NULL)
			{
				SDL_Delay((16 * 60000 / data->elements->bpm_control.bpm_value) - prev_time);
				current_time = top_time;
				prev_time = 0;
			}
		}
	}
	return 0;
}
void PlayMap(SDL_Thread** thread, PlayThread* playThread)
{
	*thread = SDL_CreateThread(PlayChannel, "OnPlay", (void*)playThread);
}