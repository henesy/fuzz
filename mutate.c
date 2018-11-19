#include "fuzz.h"

/* Removed as can't shift a void pointer since unknown size, ask Sean
void
shift_val(void* in_val)
{
	int shifter = rand() % (4 + 1 - 0) + 0;
	(*in_val) << shifter;
}
*/

void
mut_int(int* in_val)
{
	int shifter = rand() % (4 + 1 - 0) + 0;
	(*in_val) << shifter;
}

void
mut_uint(unsigned int* in_val)
{
	int shifter = rand() % (4 + 1 - 0) + 0;
	(*in_val) << shifter;
}

void
mut_charstar(char** in_val)
{
}

void
mut_ucharstar(unsigned char** in_val)
{
}

/*
void
mut_charstar_arr(char*[]* in_val)
{
	int shifter = rand() % (4 + 1 - 0) + 0;
	(*in_val) << shifter;
}*/

void
mut_long(long* in_val)
{
	int shifter = rand() % (4 + 1 - 0) + 0;
	(*in_val) << shifter;
}

void
mut_longstar(long** in_val)
{
}

void
mut_ulong(unsigned long* in_val)
{
	int shifter = rand() % (4 + 1 - 0) + 0;
	(*in_val) << shifter;
}

void
mut_vlong(long long* in_val)
{
	int shifter = rand() % (4 + 1 - 0) + 0;
	(*in_val) << shifter;
}

void
mut_void(void* in_val)
{
}

void
mut_voidstar(void** in_val)
{
}

void
mut_IOchunk(IOchunk* in_val)
{	
}

void
mut_IOchunkstar(IOchunk** in_val)
{
}

void
mut_dir(Dir* in_val)
{
}

void
mut_dirstar(Dir** in_val)
{
}

void
mut_dirstar_star(Dir*** in_val)
{
}
