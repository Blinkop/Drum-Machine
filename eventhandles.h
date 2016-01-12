#ifndef _EVENTHANDLES_H_
#define _EVENTHANDLES_H_

#include "threadmanager.h"
#include "timelist.h"

bool CatchUpEvents(SDL_Window*, GUI_elements*, SDL_Renderer*, FramesChange*);
bool MouseOnButton(DM_Button);
bool MouseOnRect(SDL_Rect);
bool MouseOnPad(DM_channel);

void Unpress(Uint8, FramesChange*, GUI_elements*, SDL_Renderer*);
#endif