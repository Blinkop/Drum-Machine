#include "timelist.h"

t_list* create(BST time, uint8_t id)
{
	t_list* list = (t_list*)malloc(sizeof(t_list));
	list->id = id;
	list->time = time;
	return list;
}
void push_after(t_list** list, BST time, uint8_t id, uint32_t index)
{
	t_list* element = NULL;
	uint32_t size = ListSize(*list);
	if (size == 0)
	{
		push_front(list, time, id);
		return;
	}
	if (index > size) return;
	if (index == 0)
	{
		push_front(list, time, id);
	}
	else if (index == size)
	{
		push_back(list, time, id);
	}
	else
	{
		t_list* lost_element = getNode(*list, index);
		element = create(time, id);
		getNode(*list, index - 1)->next = element;
		element->next = lost_element;
	}
}
void push_front(t_list** list, BST time, uint8_t id)
{
	t_list* front_element = create(time, id);
	front_element->next = *list;
	*list = front_element;
}
void push_back(t_list** list, BST time, uint8_t id)
{
	if (*list == NULL)
	{
		*list = create(time, id);
		(*list)->next = NULL;
	}
	if ((*list)->next == NULL)
	{
		t_list* new_time = create(time, id);
		new_time->next = NULL;
		(*list)->next = new_time;
	}
	else
	{
		t_list* local = *list;
		while (local->next) local = local->next;
		push_back(&local, time, id);
	}
}
void push_time(t_list** list, BST time, uint8_t id, Uint16 BPM)
{
	t_list* local = *list;
	uint32_t i = 0;
	while (local != NULL && timeTransform(local->time, BPM) <= timeTransform(time, BPM))
	{
		local = local->next;
		i++;
	}
	push_after(list, time, id, i);
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
BST getTimeValue(t_list* list, uint32_t index)
{
	uint32_t i;
	t_list* link = list;
	for (i = 0; i < index; ++i)
	{
		link = link->next;
	}
	return link->time;
}
void TimeDelete(t_list** list)
{
	Uint32 size = ListSize(*list);
	t_list* next = *list;
	t_list* local = NULL;
	for (Uint32 i = 0; i < size; ++i)
	{
		local = next->next;
		free(next);
		next = local;
	}
	*list = NULL;
}