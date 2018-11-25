#include "fuzz.h"

// HERE BE DRAGONS -- this should be moved to a generator
// Generate the input list for the given syscall

void mk_int(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = malloc(sizeof(int));
    *(int *)tt->var = 0;
    tt->t = t_int;

    ladd(l, tt);
}

void mk_intS(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = nil;
    tt->t = t_intS;

    ladd(l, tt);
}

void mk_uint(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = malloc(sizeof(unsigned int));
    *(unsigned int *)tt->var = 0;
    tt->t = t_uint;

    ladd(l, tt);
}

void mk_IOchunkS(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = nil;
    tt->t = t_IOchunkS;

    ladd(l, tt);
}

void mk_long(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = malloc(sizeof(long));
    *(long *)tt->var = 0;
    tt->t = t_long;

    ladd(l, tt);
}

void mk_longS(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = nil;
    tt->t = t_longS;

    ladd(l, tt);
}

void mk_ulong(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = malloc(sizeof(unsigned long));
    *(unsigned long *)tt->var = 0;
    tt->t = t_ulong;

    ladd(l, tt);
}

void mk_vlong(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = malloc(sizeof(long long));
    *(long long *)tt->var = 0;
    tt->t = t_vlong;

    ladd(l, tt);
}

void mk_DirS(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = nil;
    tt->t = t_DirS;

    ladd(l, tt);
}

void mk_DirSS(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = nil;
    tt->t = t_DirSS;

    ladd(l, tt);
}

void mk_char(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = malloc(sizeof(char));
    *(char *)tt->var = '\n';
    tt->t = t_char;

    ladd(l, tt);
}

void mk_uchar(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = malloc(sizeof(unsigned char));
    *(unsigned char *)tt->var = '\n';
    tt->t = t_uchar;

    ladd(l, tt);
}

void mk_ucharS(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = nil;
    tt->t = t_ucharS;

    ladd(l, tt);
}

void mk_charS(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = malloc(1* sizeof(char*));
    tt->t = t_charS;

    ladd(l, tt);
}

void mk_void(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = nil;
    tt->t = t_void;

    ladd(l, tt);
}

void mk_voidS(List *l)
{
    t_type *tt = malloc(sizeof(t_type));
    tt->var = nil;
    tt->t = t_voidS;

    ladd(l, tt);
}

List*
mkinlist(List* l, call c)
{
	// Iterate through l

	switch(c){
	case sc_abort:
        mk_void(l);
		break;
	case sc_access:
        mk_charS(l);
        mk_int(l);
		break;
	case sc_alarm:
        mk_ulong(l);
		break;
	case sc_await:
        mk_charS(l);
        mk_int(l);
		break;
    case sc_bind:
        mk_charS(l);
        mk_charS(l);
        mk_int(l);
        break;
	case sc_brk:
        mk_voidS(l);
		break;
	case sc_chdir:
		mk_charS(l);
		break;
	case sc_close:
        mk_int(l);
		break;
	case sc_create:
        mk_charS(l);
        mk_int(l);
        mk_ulong(l);
		break;
	case sc_dup:
        mk_int(l);
        mk_int(l);
		break;
	case sc_errstr:
        mk_charS(l);
        mk_uint(l);
		break;
	case sc_exec:

        // wtf?

		break;
	case sc_execl:
        mk_charS(l);
		break;
	case sc_exits:
        mk_charS(l);
	    break;
    case sc_fork:
        mk_void(l);
		break;
	case sc_rfork:
        mk_int(l);
		break;
	case sc_fauth:
        mk_int(l);
        mk_charS(l);
		break;
	case sc_fstat:
        mk_int(l);
        mk_ucharS(l);
        mk_int(l);
		break;
	case sc_fwstat:
        mk_int(l);
        mk_ucharS(l);
        mk_int(l);
		break;
	case sc_fversion:
        mk_int(l);
        mk_int(l);
        mk_charS(l);
        mk_int(l);
		break;
	case sc_mount:
        mk_int(l);
        mk_int(l);
        mk_charS(l);
        mk_int(l);
        mk_charS(l);
		break;
	case sc_unmount:
        mk_charS(l);
        mk_charS(l);
		break;
	case sc_noted:
        mk_int(l);
		break;
	case sc_notify:

        // wtf?

		break;
	case sc_open:
        mk_charS(l);
        mk_int(l);
		break;
	case sc_fd2path:
        mk_int(l);
        mk_charS(l);
        mk_int(l);
		break;
	case sc_pipe:
        mk_intS(l);
		break;
	case sc_pread:
        mk_int(l);
        mk_voidS(l);
        mk_long(l);
        mk_vlong(l);
		break;
	case sc_preadv:
        mk_int(l);
        mk_IOchunkS(l);
        mk_int(l);
        mk_vlong(l);
		break;
	case sc_pwrite:
        mk_int(l);
        mk_voidS(l);
        mk_long(l);
        mk_vlong(l);
		break;
	case sc_pwritev:
        mk_int(l);
        mk_IOchunkS(l);
        mk_int(l);
        mk_vlong(l);
		break;
	case sc_read:
        mk_int(l);
        mk_voidS(l);
        mk_long(l);
		break;
	case sc_readn:
        mk_int(l);
        mk_voidS(l);
        mk_long(l);
		break;
	case sc_readv:
        mk_int(l);
        mk_IOchunkS(l);
        mk_int(l);
		break;
	case sc_remove:
        mk_charS(l);
		break;
	case sc_sbrk:
        mk_ulong(l);
		break;
	case sc_oseek:
        mk_int(l);
        mk_long(l);
        mk_int(l);
		break;
	case sc_seek:
        mk_int(l);
        mk_vlong(l);
        mk_int(l);
		break;
	case sc_segattach:
        mk_int(l);
        mk_charS(l);
        mk_voidS(l);
        mk_ulong(l);
		break;
	case sc_segbrk:
        mk_voidS(l);
        mk_voidS(l);
		break;
	case sc_segdetach:
        mk_voidS(l);
		break;
	case sc_segflush:
        mk_voidS(l);
        mk_ulong(l);
		break;
	case sc_segfree:
        mk_voidS(l);
        mk_ulong(l);
		break;
	case sc_semacquire:
        mk_longS(l);
        mk_int(l);
		break;
	case sc_semrelease:
        mk_longS(l);
        mk_long(l);
		break;
	case sc_sleep:
        mk_long(l);
		break;
	case sc_stat:
        mk_charS(l);
        mk_ucharS(l);
        mk_int(l);
		break;
	case sc_tsemacquire:
        mk_longS(l);
        mk_ulong(l);
		break;
	case sc_wait:
        mk_void(l);
		break;
	case sc_waitpid:
        mk_void(l);
		break;
	case sc_write:
        mk_int(l);
        mk_voidS(l);
        mk_long(l);
		break;
	case sc_writev:
        mk_int(l);
        mk_IOchunkS(l);
        mk_int(l);
		break;
	case sc_wstat:
        mk_charS(l);
        mk_ucharS(l);
        mk_int(l);
		break;
	case sc_rendezvous:
        mk_voidS(l);
        mk_voidS(l);
		break;
	case sc_dirstat:
        mk_charS(l);
		break;
	case sc_dirfstat:
        mk_int(l);
		break;
	case sc_dirwstat:
        mk_charS(l);
        mk_DirS(l);
		break;
	case sc_dirfwstat:
        mk_int(l);
        mk_DirS(l);
		break;
	case sc_dirread:
        mk_int(l);
        mk_DirSS(l);
		break;
	case sc_nulldir:
        mk_DirS(l);
		break;
	case sc_dirreadall:
        mk_int(l);
        mk_DirSS(l);
		break;
	case sc_getpid	:
        mk_void(l);
		break;
	case sc_getppid:
        mk_void(l);
		break;
	case sc_rerrstr:
        mk_charS(l);
        mk_uint(l);
		break;
	case sc_sysname:
        mk_void(l);
		break;
	case sc_werrstr:
        mk_charS(l);
		break;
	}

	return nil;
}
