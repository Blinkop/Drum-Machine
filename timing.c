#include "timing.h"

void getSignalTime(TimeLapse* bar, Uint16 BPM)
{
	bar->beat = getCurrentTime(bar, BPM) / (4 * 60000 / BPM);
	bar->step = (16 * getCurrentTime(bar, BPM) / (4 * 60000 / BPM)) % 16;
	bar->tick = (256 * getCurrentTime(bar, BPM) / (4 * 60000 / BPM)) % 16;
}
Uint32 getCurrentTime(TimeLapse* bar, Uint16 BPM)
{
	Uint32 time = 0;
	if (bar->started)
	{
		if (bar->paused)
		{
			time = bar->pausedTime;
		}
		else
		{
			time = SDL_GetTicks() - bar->startedTime;
			time = time % (16 * 60000 / BPM);
		}
	}
	return time;
}