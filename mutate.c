#include "fuzz.h"

#ifndef ROUND_NUM
#define ROUND_NUM 1
#endif // ROUND_NUM

void
mut_int(int* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        *in_val = rng();
    }
    else
    {
        *in_val = *in_val << (rng() % (4 + 1 - 0) + 0);
        // Segfaults when fuzzing close() ↓
        *in_val = *in_val |= (rng() % (15 + 1 - 0) + 0);
    }
}

void
mut_intstar(int** in_val, int* round)
{
	// TODO -- Sean sanity check plz
	if(*round == ROUND_NUM)
	{
		in_val = (int**) malloc(sizeof(int*));
		*in_val = (int*) malloc(sizeof(int));
		**in_val = rng();
	}
	else
	{
	        (**in_val) << (rng() % (4 + 1 - 0) + 0);
        	(**in_val) |= (rng() % (15 + 1 - 0) + 0);
	}
}

void
mut_uint(unsigned int* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        *in_val = rng();
    }
    else
    {
        (*in_val) << (rng() % (4 + 1 - 0) + 0);
        (*in_val) |= (rng() % (15 + 1 - 0) + 0);
    }
}

void
mut_charstar(char** in_val, int *round)
{
    // if not round 1, free the previously malloc-ed memory
    if(*round != ROUND_NUM && *round != 0)
        free(*in_val);

    const int MAX_SIZE = 2048;
    int size = rng() % MAX_SIZE + 1;

		in_val = malloc(sizeof(char*) * 1);
    *in_val = malloc(sizeof(char) * size);

    int i;
    for(i = 0; i < size; i++)
    {
        (*in_val)[i] = rng() % 255;
    }
    (*in_val)[size - 1] = '\0';


    dolog("[mutate.c mut_charstar] Value of in_val: %s\n", *in_val);
}

void
mut_ucharstar(unsigned char** in_val, int *round)
{
    // if not round 1, free the previously malloc-ed memory
    if(*round != ROUND_NUM)
        free(*in_val);

    const int MAX_SIZE = 2048;
    int size = rng() % MAX_SIZE + 1;

    *in_val = malloc(sizeof(char) * size);

    int i;
    for(i = 0; i < size; i++)
    {
        (*in_val)[i] = rng() % 255;
    }
    (*in_val)[size - 1] = '\0';
}

int
mut_charstararr(char*** in_val, int *round)
{
    int length = (rng() % (64 + 1 - 1) + 1);

    return length;
}

void
mut_long(long* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        *in_val = (rng() << 16) | rng();
    }
    else
    {
        (*in_val) << (rng() % (4 + 1 - 0) + 0);
        (*in_val) |= (rng() % (15 + 1 - 0) + 0);
    }
}

void
mut_longstar(long** in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
	// TODO -- check that this is correct
	in_val = (long**) malloc(sizeof(long*));
	*in_val = (long*) malloc(sizeof(long));
	**in_val = (rng() << 16) | rng();
    }
    else
    {
	(**in_val) << (rng() % (4 + 1 - 0) + 0);
	// Segfaults when fuzzing sleep ↓
	(**in_val) |= (rng() % (15 + 1 - 0 ) + 0);
    }
}

void
mut_ulong(unsigned long* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        *in_val = (rng() << 16) | rng();
    }
    else
    {
        (*in_val) << (rng() % (4 + 1 - 0) + 0);
        (*in_val) |= (rng() % (15 + 1 - 0) + 0);
    }
}

void
mut_vlong(long long* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        *in_val = (rng() << 48) | (rng() << 32) | (rng() << 16) | rng();
    }
    else
    {
        (*in_val) << (rng() % (4 + 1 - 0) + 0);
        (*in_val) |= (rng() % (15 + 1 - 0) + 0);
    }
}

void
mut_void(void* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        //*in_val = rng();
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
        //*in_val = rng();
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
        //*in_val = rng();
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
        //*in_val = rng();
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
        //*in_val = rng();
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
        //*in_val = rng();
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
        //*in_val = rng();
    }
    else
    {
    }
}
