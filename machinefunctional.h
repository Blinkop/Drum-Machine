#ifndef _MACHINEFUNCTIONAL_H_
#define _MACHINEFUNCTIONAL_H_

#include "includes.h"
#include "timing.h"
#include "machineelements.h"
#include "timelist.h"

void Record();
void Play(TimeLapse*);
void Pause();
void Stop(TimeLapse*);
void ToStart(TimeLapse*);
void Clear(t_list**);
void Quantize(t_list*);
char* updateTime(TimeLapse*, char*, Uint16);

#endif