#include "timing.h"

void getSignalTime(TimeLapse* bar, Uint16 BPM)
{
	bar->beat = getCurrentTime(bar, BPM) / (4 * 60000 / BPM);
	bar->step = (16 * getCurrentTime(bar, BPM) / (4 * 60000 / BPM)) % 16;
	bar->tick = (256 * getCurrentTime(bar, BPM) / (4 * 60000 / BPM)) % 16;
}
BST getSignTime(TimeLapse* bar, Uint16 BPM)
{
	BST bst;
	Uint32 CurrentTime = getCurrentTime(bar, BPM);
	bst.beat = CurrentTime / (4 * 60000 / BPM);
	bst.step = (16 * CurrentTime / (4 * 60000 / BPM)) % 16;
	bst.tick = (256 * CurrentTime / (4 * 60000 / BPM)) % 16;
	return bst;
}
Uint32 timeTransform(BST bst, Uint16 BPM)
{
	Uint32 tickedTime;
	Uint16 loopLength = 4 * 60000 / BPM;
	tickedTime = bst.beat * loopLength + bst.step * loopLength / 16 + bst.tick * loopLength / 256;
	return tickedTime;
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
Uint32 getTickedTime(TimeLapse* bar, Uint16 BPM)
{
	Uint32 tickedTime;
	Uint16 loopLength = 4 * 60000 / BPM;
	getSignalTime(bar, BPM);
	tickedTime = bar->beat * loopLength + bar->step * loopLength / 16 + bar->tick * loopLength / 256;
	return tickedTime;
}