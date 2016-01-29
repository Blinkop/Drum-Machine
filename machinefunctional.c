#include "machinefunctional.h"

void Play(TimeLapse* lapse)
{
	lapse->started = true;
	lapse->startedTime = SDL_GetTicks();
}
void Pause()
{

}
void Stop(TimeLapse* lapse)
{
	lapse->started = false;
	lapse->startedTime = 0;
	lapse->pausedTime = 0;
}
void ToStart(TimeLapse* lapse)
{
	Stop(lapse);
	Play(lapse);
}
void Quantize(t_list* list)
{
	t_list* local = list;
	while (local)
	{
		local->time.tick = 0;
		local = local->next;
	}
}
void Record()
{

}
void Clear(t_list** list)
{
	TimeDelete(list);
}
char* updateTime(TimeLapse* time, char* buf, Uint16 BPM)
{
	sprintf_s(buf, 12, "%d : %02d : %02d\0", time->beat, time->step, time->tick);
	return buf;
}