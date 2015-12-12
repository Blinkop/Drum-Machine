#ifndef _MACHINEELEMENTS_H_
#define _MACHINEELEMENTS_H_

#include "includes.h"

#define PRESSED 1
#define UNPRESSED 0

typedef struct DM_channel
{
	SDL_Texture* pad;
	SDL_Rect rect;
} DM_channel;

typedef struct FramesChange
{
	SDL_Texture* pad;
	SDL_Texture* padPressed;
} FramesChange;

typedef struct GUI_elements
{
	DM_channel pad_1;
	DM_channel pad_2;
	DM_channel pad_3;
	DM_channel pad_4;
	DM_channel pad_5;
	DM_channel pad_6;
	DM_channel pad_7;
	DM_channel pad_8;
	DM_channel pad_9;
	DM_channel pad_10;
	DM_channel pad_11;
	DM_channel pad_12;
	DM_channel pad_13;
	DM_channel pad_14;
	DM_channel pad_15;
	DM_channel pad_16;
	SDL_Texture* padsFrame;
	SDL_Texture* functionalFrame;
	SDL_Texture* channelsFrame;
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