#ifndef _MACHINEFUNCTIONAL_H_
#define _MACHINEFUNCTIONAL_H_

#include "includes.h"
#include "timing.h"
#include "machineelements.h"

void Record();
void Play(TimeLapse*);
void Pause();
void Stop(TimeLapse*);
void ToStart();
void Quantize();
char* updateTime(TimeLapse*, char*, Uint16);

#endif