#include "fuzz.h"

/* Removed as can't shift a void pointer since unknown size, ask Sean
void
shift_val(void* in_val, int *round)
{
	int shifter = rand() % (4 + 1 - 0) + 0;
	(*in_val) << shifter;
}
*/

#ifndef ROUND_NUM
#define ROUND_NUM 1
#endif // ROUND_NUM

void
mut_int(int* in_val, int *round)
{
//    if(*round == ROUND_NUM)
//    {
//        *in_val = rand();
//    }
//    else
//    {
        (*in_val) << (rand() % (4 + 1 - 0) + 0);
        (*in_val) |= (rand() % (15 + 1 - 0) + 0);
//    }
}

void
mut_uint(unsigned int* in_val, int *round)
{
//    if(*round == ROUND_NUM)
//    {
//        *in_val = rand();
//    }
//    else
//    {
        (*in_val) << (rand() % (4 + 1 - 0) + 0);
        (*in_val) |= (rand() % (15 + 1 - 0) + 0);
//    }
}

void
mut_charstar(char** in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        //*in_val = rand();
    }
    else
    {

    }
}

void
mut_ucharstar(unsigned char** in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        //*in_val = rand();
    }
    else
    {
    }
}

/*
void
mut_charstar_arr(char*[]* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        *in_val = rand();
    }
    else
    {
	int shifter = rand() % (4 + 1 - 0) + 0;
	(*in_val) << shifter;
}*/

void
mut_long(long* in_val, int *round)
{
//    if(*round == ROUND_NUM)
//    {
//        //*in_val = rand();
//    }
//    else
//    {
        (*in_val) << (rand() % (4 + 1 - 0) + 0);
        (*in_val) |= (rand() % (15 + 1 - 0) + 0);
//    }
}

void
mut_longstar(long** in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        //*in_val = rand();
    }
    else
    {
    }
}

void
mut_ulong(unsigned long* in_val, int *round)
{
//    if(*round == ROUND_NUM)
//    {
//        //*in_val = rand();
//    }
//    else
//    {
        (*in_val) << (rand() % (4 + 1 - 0) + 0);
        (*in_val) |= (rand() % (15 + 1 - 0) + 0);
//    }
}

void
mut_vlong(long long* in_val, int *round)
{
//    if(*round == ROUND_NUM)
//    {
//        //*in_val = rand();
//    }
//    else
//    {
        (*in_val) << (rand() % (4 + 1 - 0) + 0);
        (*in_val) |= (rand() % (15 + 1 - 0) + 0);
//    }
}

void
mut_void(void* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        //*in_val = rand();
    }
    else
    {
    }
}

void
mut_voidstar(void** in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        //*in_val = rand();
    }
    else
    {
    }
}

void
mut_IOchunk(IOchunk* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        //*in_val = rand();
    }
    else
    {
    }
}

void
mut_IOchunkstar(IOchunk** in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        //*in_val = rand();
    }
    else
    {
    }
}

void
mut_dir(Dir* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        //*in_val = rand();
    }
    else
    {
    }
}

void
mut_dirstar(Dir** in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        //*in_val = rand();
    }
    else
    {
    }
}

void
mut_dirstar_star(Dir*** in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        //*in_val = rand();
    }
    else
    {
    }
}
