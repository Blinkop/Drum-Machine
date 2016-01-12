#include "timelist.h"

t_list* create(uint32_t time)
{
	t_list* list = (t_list*)malloc(sizeof(t_list));
	list->time = time;
	return list;
}
void push_after(t_list** list, uint32_t time, uint32_t index)
{
	t_list* element = NULL;
	uint32_t size = ListSize(*list);
	if (size == 0)
	{
		push_front(list, time);
		return;
	}
	if (index > size) return;
	if (index == size)
	{
		push_back(list, time);
	}
	else
	{
		t_list* lost_element = getNode(*list, index);
		element = create(time);
		getNode(*list, index - 1)->next = element;
		element->next = lost_element;
	}
}
void push_front(t_list** list, uint32_t time)
{
	t_list* front_element = create(time);
	front_element->next = *list;
	*list = front_element;
}
void push_back(t_list** list, uint32_t time)
{
	if (*list == NULL)
	{
		*list = create(time);
		(*list)->next = NULL;		
	}
	if ((*list)->next == NULL)
	{
		t_list* new_time = create(time);
		new_time->next = NULL;
		(*list)->next = new_time;
	}
	else
	{
		t_list* local = *list;
		while (local->next) local = local->next;
		push_back(&local, time);
	}
}
void push_time(t_list** list, uint32_t time)
{
	t_list* local = *list;
	uint32_t i = 0;
	while (local != NULL && local->time <= time)
	{
		local = local->next;
		i++;
	}
	push_after(list, time, i);
}
t_list* getNode(t_list* list, uint32_t index)
{
	uint32_t i;
	t_list* link = list;
	for (i = 0; i < index; i++)
	{
		link = link->next;
	}
	return link;
}
uint32_t ListSize(t_list* list)
{
	t_list* local_list = list;
	uint32_t size = 0;
	while (local_list)
	{
		local_list = local_list->next;
		size++;
	}
	return size;
}
uint32_t getTimeValue(t_list* list, uint32_t index)
{
	uint32_t i;
	t_list* link = list;
	for (i = 0; i < index - 1; i++)
	{
		link = link->next;
	}
	return link->time;
}