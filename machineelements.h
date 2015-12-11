#ifndef _MACHINEELEMENTS_H_
#define _MACHINEELEMENTS_H_

#include "includes.h"

#define PRESSED 1
#define UNPRESSED 0

typedef struct GUI_elements
{
	SDL_Surface* pad_1;
	SDL_Surface* pad_2;
	SDL_Surface* pad_3;
	SDL_Surface* pad_4;
	SDL_Surface* pad_5;
	SDL_Surface* pad_6;
	SDL_Surface* pad_7;
	SDL_Surface* pad_8;
	SDL_Surface* pad_9;
	SDL_Surface* pad_10;
	SDL_Surface* pad_11;
	SDL_Surface* pad_12;
	SDL_Surface* pad_13;
	SDL_Surface* pad_14;
	SDL_Surface* pad_15;
	SDL_Surface* pad_16;
	SDL_Surface* padsFrame;
	SDL_Surface* functionalFrame;
	SDL_Surface* channelsFrame;
} GUI_elements;

enum KeyPressEnum
{
	KEY_PRESS_PLAY_PAUSE,
	KEY_PRESS_PAD_1,
	KEY_PRESS_PAD_2,
	KEY_PRESS_PAD_3,
	KEY_PRESS_PAD_4,
	KEY_PRESS_PAD_5,
	KEY_PRESS_PAD_6,
	KEY_PRESS_PAD_7,
	KEY_PRESS_PAD_8,
	KEY_PRESS_PAD_9,
	KEY_PRESS_PAD_10,
	KEY_PRESS_PAD_11,
	KEY_PRESS_PAD_12,
	KEY_PRESS_PAD_13,
	KEY_PRESS_PAD_14,
	KEY_PRESS_PAD_15,
	KEY_PRESS_PAD_16,
	KEY_PRESS_RECORD,
	KEY_PRESS_STOP,
	KEYS_TOTAL
};

#endif