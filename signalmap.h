#ifndef _SIGNALMAP_H_
#define _SIGNALMAP_H_

#include <stdio.h>
#include <stdlib.h>
#include "timing.h"

FILE* openFile(char* path);
void closeFile(FILE* file);

void FillHeader(FILE* file, Uint8 channels);


#endif