#ifndef _EVENTHANDLES_H_
#define _EVENTHANDLES_H_

#include "windowoperations.h"

bool CatchUpEvents(SDL_Window*, GUI_elements*, SDL_Renderer*, FramesChange*);
bool MouseOnButton(DM_Button);
bool MouseOnRect(SDL_Rect);

void Unpress(Uint8, FramesChange*, GUI_elements*, SDL_Renderer*);
#endif