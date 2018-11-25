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
	if(*round == ROUND_NUM)
	{
		in_val = (int**) malloc(sizeof(int*));
		*in_val = (int*) malloc(sizeof(int));
		**in_val = rng();
	}
	else
	{
	    **in_val = **in_val << (rng() % (4 + 1 - 0) + 0);
        **in_val = **in_val |= (rng() % (15 + 1 - 0) + 0);
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
        *in_val = *in_val << (rng() % (4 + 1 - 0) + 0);
        *in_val = *in_val |= (rng() % (15 + 1 - 0) + 0);
    }
}

char*
mut_charstar()
{
	int size = (rng() % (256 + 1 - 2) + 2);
	char* val = calloc(size, sizeof(char));
	int i;
	for(i = 0; i < size - 1; i++)
	{
	    val[i] = rng() % 255;
	}    
	return val;
/*
    // if not round 1, free the previously malloc-ed memory
    if(in_val != nil)//*round != ROUND_NUM && *round != 0)
    {
    //    free(*in_val);
	debug("mut_charstar: in_val != nil\n");
    }
    if (*round == 1)
    {
        in_val = malloc(1 * sizeof(char*));
    }

    if(*round > 0){
	    const int MAX_SIZE = 256;
	    int size = rng() % MAX_SIZE + 1;

	    debug("inside mut, round: %d in_val: %p\n", *round, in_val);

	    *in_val = malloc(sizeof(char) * size);
	    // in_val = malloc(size * sizeof(char));

	    int i;
	    for(i = 0; i < size; i++)
	    {
		(*in_val)[i] = rng() % 255;
	    }
	    (*in_val)[size - 1] = '\0';
    debug("mut_charstar: *in_val : %s\n", *in_val);
    debug("mut_charstar: in_val : %p\n", in_val);
	
    }
*/
/*	if (*round == 1)
	{
		char** c = malloc(1 * sizeof(char*));
		in_val = c;
	}
	if (*round > 0)
	{
		const int MAX_SIZE = 256;
	    	int size = rng() % MAX_SIZE + 1;

	    	debug("inside mut, round: %d in_val: %p\n", *round, in_val);

		char** c = (char**) in_val;
		*c = malloc(size * sizeof(char));
		debug("inside mut, round %d c: %p in_val: %p\n", *round, c, in_val);
		int i;
		for(i = 0; i < size; i++)
		{
			(*c)[i] = rng() % 255;
		}
		(*c)[size - 1] = '\0';

	}*/
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
mut_charstararr(char*** in_val)
{
    int length = (rng() % (16 + 1 - 1) + 1);
	dolog("Length: %d", length);
	hjsync();
    // malloc the pointer to the array
    in_val = malloc(sizeof(char*));
    // malloc the pointer to the char arrays
    *in_val = malloc(length * sizeof(char*));

    int y, z;
    for (y = 0; y < length; y++)
    {
        // malloc the char arrays
	int size = (rng() % (64 + 1 - 2) + 2);
	*in_val[y] = calloc(size, sizeof(char));
	// init the chars to rng values
	for (z = 0; z < size - 1; z++)
	{
	    *in_val[y][z] = (rng() % (255 + 1 - 1) + 1);
	}
    }

    return length;
}

void free_charstararr(char*** in_val, int len)
{
	int x;
	for (x = 0; x < len; x++)
	{
		free(*in_val[x]);
	}
	free(*in_val);
	free(in_val);
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
        *in_val = *in_val << (rng() % (4 + 1 - 0) + 0);
        *in_val = *in_val |= (rng() % (15 + 1 - 0) + 0);
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
        **in_val = **in_val << (rng() % (4 + 1 - 0) + 0);
	// Segfaults when fuzzing sleep ↓
        **in_val = **in_val |= (rng() % (15 + 1 - 0 ) + 0);
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
        *in_val = *in_val << (rng() % (4 + 1 - 0) + 0);
        *in_val = *in_val |= (rng() % (15 + 1 - 0) + 0);
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
        *in_val = *in_val << (rng() % (4 + 1 - 0) + 0);
        *in_val = *in_val |= (rng() % (15 + 1 - 0) + 0);
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
