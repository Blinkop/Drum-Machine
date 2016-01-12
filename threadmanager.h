#ifndef _THREADMANAGER_H_
#define _THREADMANEGER_H_

#include "windowoperations.h"
#include "timelist.h"

typedef struct TimeThread
{
	SDL_Renderer* renderer;
	GUI_elements* elements;
	TimeLapse* lapse;
} TimeThread;

typedef struct PlayThread
{
	GUI_elements* elements;
	TimeLapse* lapse;
	t_list** list;
	Uint8 id;
	SDL_Renderer* renderer;
	FramesChange* frames;
} PlayThread;

enum TimeSignals
{
	FIRST_SIGNAL_IN,
	LOOP_END,
	ON_PLAY
};

int timerStart(TimeThread* data);
int PlayChannel(PlayThread* data);

#endif