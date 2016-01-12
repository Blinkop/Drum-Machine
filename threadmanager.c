#include "threadmanager.h"

int timerStart(TimeThread* data)
{
	Uint8 beat = 0;
	Uint8 step = 0;
	Uint8 tick = 0;
	while (true)
	{
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
	}
	return 0;
}
int PlayChannel(PlayThread* data)
{
	t_list* top_time = *(data->list);
	t_list* current_time = top_time;
	t_list* prev_top = top_time;
	Uint8 id = data->id;
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
				if (current_time->time == 0)
				{
					Mix_PlayChannel(id + 1, data->elements->pad[id].sound, 0);
					puts("Sound Played!");
					NewTextureOnRender(data->renderer,
						data->elements->pad[data->id].pad, data->frames->padPressed, data->elements->pad[data->id].rect);
				}
				else
				{
					Uint32 bottomCycleTime = getCurrentTime(data->lapse, data->elements->bpm_control.bpm_value);
					SDL_Delay(current_time->time - (bottomCycleTime - topCycleTime) - prev_time);
					Mix_PlayChannel(id + 1, data->elements->pad[id].sound, 0);
					puts("Sound Played!");
					NewTextureOnRender(data->renderer,
						data->elements->pad[data->id].pad, data->frames->padPressed, data->elements->pad[data->id].rect);
				}
			}
			prev_time = current_time->time;
			current_time = current_time->next;
			/*SDL_Delay(2000);*/
			NewTextureOnRender(data->renderer,
				data->elements->pad[data->id].pad, data->frames->pad, data->elements->pad[data->id].rect);
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
void PlayMap()
{
	Uint8 i;
	for (i = 0; i < 16; i++)
	{

	}
}