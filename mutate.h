#ifndef MUT_H
#define MUT_H

void mut_int(int*, int*);

void mut_intstar(int**, int*);

void mut_uint(uint*, int*);

void mut_char(char*, int*);

char* mut_charstar(void);

unsigned char* mut_ucharstar(void);

int mut_charstararr(char***);

void free_charstararr(char***, int);

void mut_long(long*, int*);

long* mut_longstar(void);

void mut_ulong(unsigned long*, int*);

void mut_vlong(long long*, int*);

void mut_void(void*, int*);

void mut_voidstar(void**, int*);

void mut_IOchunk(IOchunk*, int*);

void mut_IOchunkstar(IOchunk**, int*);

void mut_dir(Dir*, int*);

void mut_dirstar(Dir**, int*);

void mut_dirstar_star(Dir***, int*);

#endif
