#include "fuzz.h"

// HERE BE DRAGONS -- this should be moved to a generator
// Generate the input list for the given syscall
List*
mkinlist(List* l, call c)
{
	switch(c){
	case sc_exits	:
	
	case sc_abort	:
	 
	case sc_access	:
	 
	case sc_alarm	:
	 
	case sc_await	:
	 
	case sc_bind	:
	 
	case sc_brk	:
	 
	case sc_chdir	:
	 
	case sc_close	:

	case sc_create	:
	 
	case sc_dup	:
	 
	case sc_errstr	:
	 
	case sc_exec	:
	 
	case sc_execl	:
	 
	case sc_fork	:
	 
	case sc_rfork	:
	 
	case sc_fauth	:
	 
	case sc_fstat	:
	 
	case sc_fwstat	:
	 
	case sc_fversion:
	 
	case sc_mount	:
	 
	case sc_unmount:
	 
	case sc_noted	:
	 
	case sc_notify	:
	 
	case sc_open	:
	 
	case sc_fd2path:
	 
	case sc_pipe	:
	 
	case sc_pread	:
	 
	case sc_preadv:
	 
	case sc_pwrite	:
	 
	case sc_pwritev:
	 
	case sc_read	:
	 
	case sc_readn	:
	 
	case sc_readv	:
	 
	case sc_remove:
	 
	case sc_sbrk	:
	 
	case sc_oseek	:
	 
	case sc_seek:
	 
	case sc_segattach:
	 
	case sc_segbrk	:
	 
	case sc_segdetach:
	 
	case sc_segflush:
	 
	case sc_segfree:
	 
	case sc_semacquire:
	 
	case sc_semrelease:
	 
	case sc_sleep:
	 
	case sc_stat:
	 
	case sc_tsemacquire:
	 
	case sc_wait:
	 
	case sc_waitpid:
	 
	case sc_write:
	 
	case sc_writev:
	 
	case sc_wstat:
	 
	case sc_rendezvous:
	 
	case sc_dirstat:
	 
	case sc_dirfstat:
	 
	case sc_dirwstat:
	 
	case sc_dirfwstat:
	 
	case sc_dirread:
	 
	case sc_nulldir:
	 
	case sc_dirreadall:
	 
	case sc_getpid	:
	 
	case sc_getppid:
	 
	case sc_rerrstr:
	 
	case sc_sysname:
	 
	case sc_werrstr:
	 
	default:
		return nil;
	}
}
