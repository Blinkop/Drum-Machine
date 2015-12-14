#ifndef _TIMING_H_
#define _TIMING_H_

#include "includes.h"

typedef struct TimeLapse
{
	bool started;
	bool paused;
	Uint8 beat;
	Uint8 step;
	Uint8 tick;
	Uint32 startedTime;
	Uint32 pausedTime;

} TimeLapse;

void getSignalTime(TimeLapse* bar, Uint16 BPM);
Uint32 getCurrentTime(TimeLapse* bar, Uint16 BPM);


#endif