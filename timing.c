#include "timing.h"

void getSignalTime(TimeLapse* bar, Uint16 BPM)
{
	bar->beat = getCurrentTime(bar, BPM) / 4000;
	bar->step = (16 * getCurrentTime(bar, BPM) / 2000) % 16;
	bar->tick = (256 * getCurrentTime(bar, BPM) / 2000) % 16; //Is it right value?
}
Uint32 getCurrentTime(TimeLapse* bar, Uint16 BPM)
{
	Uint32 time = SDL_GetTicks() - bar->startedTime;
	time = time % (16 * 60000 / BPM);
	return time;
}