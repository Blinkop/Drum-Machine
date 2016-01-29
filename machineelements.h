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

typedef struct Label
{
	SDL_Texture* bar_clock;
	TTF_Font* font;
	SDL_Rect rect;
	SDL_Color color;
} Label;

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

typedef struct DM_BPM
{
	SDL_Rect rect;
	Uint16 bpm_value;
	SDL_Texture* BPMtexture;
} DM_BPM;

typedef struct Frame
{
	SDL_Texture* frame;
	SDL_Rect rect;
} Frame;

typedef struct GUI_elements
{
	DM_channel pad[16];
	DM_Button PlayButton;
	DM_Button StopButton;
	DM_Button PauseButton;
	DM_Button ToStartButton;
	DM_Button RecordButton;
	DM_Button ClearButton;
	DM_Button QuantizeButton;
	Frame padsFrame;
	Frame functionalFrame;
	Frame channelsFrame;
	Frame backBround;
	DM_BPM bpm_control;
	Label barClock;
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
enum KeyPressEnum
{
	
};

#endif