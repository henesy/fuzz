#include "fuzz.h"

#ifndef ROUND_NUM
#define ROUND_NUM 1
#endif // ROUND_NUM

void
mut_int(int* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
	dolog("First seeding of rand\n");
        *in_val = rand();
    }
    else
    {
        (*in_val) << (rand() % (4 + 1 - 0) + 0);
        // Segfaults when fuzzing close() ↓
        (*in_val) |= (rand() % (15 + 1 - 0) + 0);
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
		**in_val = rand();
	}
	else
	{
	        (**in_val) << (rand() % (4 + 1 - 0) + 0);
        	(**in_val) |= (rand() % (15 + 1 - 0) + 0);
	}
}

void
mut_uint(unsigned int* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        *in_val = rand();
    }
    else
    {
        (*in_val) << (rand() % (4 + 1 - 0) + 0);
        (*in_val) |= (rand() % (15 + 1 - 0) + 0);
    }
}

void
mut_charstar(char** in_val, int *round)
{
    // if not round 1, free the previously malloc-ed memory
    if(*round != ROUND_NUM && *round != 0)
        free(*in_val);

    const int MAX_SIZE = 2048;
    int size = rand() % MAX_SIZE + 1;

		in_val = malloc(sizeof(char*) * 1);
    *in_val = malloc(sizeof(char) * size);

    int i;
    for(i = 0; i < size; i++)
    {
        (*in_val)[i] = rand() % 255;
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
    int size = rand() % MAX_SIZE + 1;

    *in_val = malloc(sizeof(char) * size);

    int i;
    for(i = 0; i < size; i++)
    {
        (*in_val)[i] = rand() % 255;
    }
    (*in_val)[size - 1] = '\0';
}

int
mut_charstararr(char*** in_val, int *round)
{
    int length = (rand() % (64 + 1 - 1) + 1);

    return length;
}

void
mut_long(long* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        *in_val = (rand() << 16) | rand();
    }
    else
    {
        (*in_val) << (rand() % (4 + 1 - 0) + 0);
        (*in_val) |= (rand() % (15 + 1 - 0) + 0);
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
	**in_val = (rand() << 16) | rand();
    }
    else
    {
	(**in_val) << (rand() % (4 + 1 - 0) + 0);
	(**in_val) |= (rand() % (15 + 1 - 0 ) + 0);
    }
}

void
mut_ulong(unsigned long* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        *in_val = (rand() << 16) | rand();
    }
    else
    {
        (*in_val) << (rand() % (4 + 1 - 0) + 0);
        (*in_val) |= (rand() % (15 + 1 - 0) + 0);
    }
}

void
mut_vlong(long long* in_val, int *round)
{
    if(*round == ROUND_NUM)
    {
        *in_val = (rand() << 48) | (rand() << 32) | (rand() << 16) | rand();
    }
    else
    {
        (*in_val) << (rand() % (4 + 1 - 0) + 0);
        (*in_val) |= (rand() % (15 + 1 - 0) + 0);
    }
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
