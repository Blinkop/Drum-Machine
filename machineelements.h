#ifndef _MACHINEELEMENTS_H_
#define _MACHINEELEMENTS_H_

#include "includes.h"

#define PRESSED 1
#define UNPRESSED 0

typedef struct DM_channel
{
	SDL_Texture* pad;
	SDL_Rect rect;
	Mix_Chunk* sound;
} DM_channel;

typedef struct FramesChange
{
	SDL_Texture* pad;
	SDL_Texture* padPressed;
	SDL_Texture* Record;
	SDL_Texture* RecordPressed;
	SDL_Texture* Play;
	SDL_Texture* PlayPressed;
	SDL_Texture* Stop;
	SDL_Texture* StopPressed;
	SDL_Texture* Pause;
	SDL_Texture* PausePressed;
	SDL_Texture* ToStart;
	SDL_Texture* ToStartPressed;
	SDL_Texture* Quantize;
	SDL_Texture* QuantizePressed;
	SDL_Texture* Clear;
	SDL_Texture* ClearPressed;
} FramesChange;

typedef struct DM_Button
{
	SDL_Texture* frame;
	SDL_Rect rect;
} DM_Button;

typedef struct GUI_elements
{
	/*DM_channel pad_1;
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
	DM_channel pad_16;*/
	DM_channel pad[16];
	SDL_Texture* padsFrame;
	SDL_Texture* functionalFrame;
	SDL_Texture* channelsFrame;
	DM_Button PlayButton;
	DM_Button StopButton;
	DM_Button PauseButton;
	DM_Button ToStartButton;
	DM_Button RecordButton;
	DM_Button ClearButton;
	DM_Button QuantizeButton;
	
} GUI_elements;

enum MousePressEnum
{
	RECORD_BUTTON,
	PLAY_BUTTON,
	PAUSE_BUTTON,
	STOP_BUTTON,
	TO_START_BUTTON,
	QUANTIZE_BUTTON,
	CLEAR_BUTTON,
	BUTTONS_TOTAL,
	NO_PRESS
};

#endif