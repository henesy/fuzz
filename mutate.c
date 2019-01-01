#include "fuzz.h"
#include <libsec.h>

// This is the round where if pointers are nil we must then allocate and permutate further from
#define MALLOC_ROUND 1

void
mut_int(int* in_val, int *round)
{
    if(*round == MALLOC_ROUND)
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
	if(*round == MALLOC_ROUND)
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
    if(*round == MALLOC_ROUND)
    {
        *in_val = rng();
    }
    else
    {
        *in_val = *in_val << (rng() % (4 + 1 - 0) + 0);
        *in_val = *in_val |= (rng() % (15 + 1 - 0) + 0);
    }
}

// Create a mutated char*
char*
mut_charstar()
{
	int size = (rng() % (64 + 1 - 2) + 2);
	char* val = calloc(size, sizeof(char));
	int i;
	for(i = 0; i < size - 1; i++)
	{
	    val[i] = rng() % 255;
	}    
	return val;

	/*
	int size = (rng() % (64 + 1 - 2) + 2);
	char* val = calloc(size, sizeof(char));
	genrandom(val, size);
	return val;
	*/
}

unsigned char*
mut_ucharstar()
{
	int size = (rng() % (64 + 1 - 2) + 2);
	uchar *val = calloc(size, sizeof(uchar));
	genrandom(val, size * sizeof(uchar));
	return val;
	
	/*
	int i;
	for(i = 0; i < size - 1; i++)
	{
	    val[i] = rng() % 255;
	}    
	return val;
	*/
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
    if(*round == MALLOC_ROUND)
    {
        *in_val = (rng() << 16) | rng();
    }
    else
    {
        *in_val = *in_val << (rng() % (4 + 1 - 0) + 0);
        *in_val = *in_val |= (rng() % (15 + 1 - 0) + 0);
    }
}

long*
mut_longstar()
{
	long* val = (long*) malloc(sizeof(long));
	*val = (rng() << 16) | rng();
	return val;
}

void
mut_ulong(unsigned long* in_val, int *round)
{
    if(*round == MALLOC_ROUND)
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
    if(*round == MALLOC_ROUND)
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
    if(*round == MALLOC_ROUND)
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
    if(*round == MALLOC_ROUND)
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
    if(*round == MALLOC_ROUND)
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
    if(*round == MALLOC_ROUND)
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
    if(*round == MALLOC_ROUND)
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
    if(*round == MALLOC_ROUND)
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
    if(*round == MALLOC_ROUND)
    {
        //*in_val = rng();
    }
    else
    {
    }
}
