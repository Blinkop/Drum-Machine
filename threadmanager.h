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
	SDL_Renderer* renderer;
	FramesChange* frames;
} PlayThread;

typedef struct PressDelay
{
	Uint8 id;
	SDL_Renderer* renderer;
	GUI_elements* elements;
	FramesChange* frames;
} PressDelay;

enum TimeSignals
{
	FIRST_SIGNAL_IN,
	LOOP_END,
	ON_PLAY
};

int KappaForPress(PressDelay* data);
int timerStart(TimeThread* data);
int PlayChannel(PlayThread* data);
void PlayMap(SDL_Thread** thread, PlayThread* playThread);

#endif