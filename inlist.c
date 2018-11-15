#include "fuzz.h"

// HERE BE DRAGONS -- this should be moved to a generator
// Generate the input list for the given syscall

List*
mkinlist(List* l, call c)
{
	// Iterate through l
	
	switch(c){
	// pls fix -- try removing the print
	case sc_exits: print("Adding exits…\n");
		t_type *t = malloc(1 * sizeof(t_type));
		t->var = nil;
		t->t = sc_exits;
		
		// Add to type list -- in order
		ladd(l, t);

		break;
	case sc_abort:

		break;
	case sc_access:

		break;
	case sc_alarm:

		break;
	case sc_await:

		break;
	case sc_bind	:

		break;
	case sc_brk	:

		break;
	case sc_chdir	:

		break;
	case sc_close	:

		break;
	case sc_create	:

		break;
	case sc_dup	:

		break;
	case sc_errstr	:

		break;
	case sc_exec	:

		break;
	case sc_execl	:

		break;
	case sc_fork	:

		break;
	case sc_rfork	:

		break;
	case sc_fauth	:

		break;
	case sc_fstat	:

		break;
	case sc_fwstat	:

		break;
	case sc_fversion:

		break;
	case sc_mount	:

		break;
	case sc_unmount:

		break;
	case sc_noted	:

		break;
	case sc_notify	:

		break;
	case sc_open	:

		break;
	case sc_fd2path:

		break;
	case sc_pipe	:

		break;
	case sc_pread	:

		break;
	case sc_preadv:

		break;
	case sc_pwrite	:

		break;
	case sc_pwritev:

		break;
	case sc_read	:

		break;
	case sc_readn	:

		break;
	case sc_readv	:

		break;
	case sc_remove:

		break;
	case sc_sbrk	:

		break;
	case sc_oseek	:

		break;
	case sc_seek:

		break;
	case sc_segattach:

		break;
	case sc_segbrk	:

		break;
	case sc_segdetach:

		break;
	case sc_segflush:

		break;
	case sc_segfree:

		break;
	case sc_semacquire:

		break;
	case sc_semrelease:

		break;
	case sc_sleep:

		break;
	case sc_stat:

		break;
	case sc_tsemacquire:

		break;
	case sc_wait:

		break;
	case sc_waitpid:

		break;
	case sc_write:

		break;
	case sc_writev:

		break;
	case sc_wstat:

		break;
	case sc_rendezvous:

		break;
	case sc_dirstat:

		break;
	case sc_dirfstat:

		break;
	case sc_dirwstat:

		break;
	case sc_dirfwstat:

		break;
	case sc_dirread:

		break;
	case sc_nulldir:

		break;
	case sc_dirreadall:

		break;
	case sc_getpid	:

		break;
	case sc_getppid:

		break;
	case sc_rerrstr:

		break;
	case sc_sysname:

		break;
	case sc_werrstr:

		break;

	default:
		return nil;
	}

	return nil; // Unreachable
}
