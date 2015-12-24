#ifndef _TIMELIST_H_
#define _TIMELIST_H_

#include <stdlib.h>
#include <stdint.h>

typedef struct t_list
{
	uint32_t time;
	struct t_list* next;
} t_list;

t_list* create(uint32_t);
void push_after(t_list**, uint32_t, uint32_t);
void push_front(t_list**, uint32_t);
void push_back(t_list**, uint32_t);
void push_time(t_list**, uint32_t);
t_list* getNode(t_list*, uint32_t);
uint32_t ListSize(t_list*);
uint32_t getTimeValue(t_list*, uint32_t);

#endif