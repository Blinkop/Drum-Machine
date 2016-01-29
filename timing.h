#ifndef _TIMING_H_
#define _TIMING_H_

#include "includes.h"

typedef struct TimeLapse
{
	bool started;
	bool paused;
	bool OnRecord;
	Uint8 beat;
	Uint8 step;
	Uint8 tick;
	Uint32 startedTime;
	Uint32 pausedTime;
} TimeLapse;

typedef struct BST
{
	uint8_t beat;
	uint8_t step;
	uint8_t tick;
} BST;

void getSignalTime(TimeLapse* bar, Uint16 BPM);
Uint32 getCurrentTime(TimeLapse* bar, Uint16 BPM);
Uint32 getTickedTime(TimeLapse* bar, Uint16 BPM);

BST getSignTime(TimeLapse* bar, Uint16 BPM);
Uint32 timeTransform(BST bst, Uint16 BPM);

#endif