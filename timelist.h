#ifndef _TIMELIST_H_
#define _TIMELIST_H_

#include <stdlib.h>
#include <stdint.h>
#include "timing.h"

typedef struct t_list
{
	BST time;
	uint8_t id;
	struct t_list* next;
} t_list;

t_list* create(BST, uint8_t);
void push_after(t_list**, BST, uint8_t, uint32_t);
void push_front(t_list**, BST, uint8_t);
void push_back(t_list**, BST, uint8_t);
void push_time(t_list**, BST, uint8_t, Uint16);
void TimeDelete(t_list**);
t_list* getNode(t_list*, uint32_t);
uint32_t ListSize(t_list*);
BST getTimeValue(t_list*, uint32_t);

#endif