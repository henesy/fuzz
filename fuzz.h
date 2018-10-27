#ifndef FUZZ_H
#define FUZZ_H

/* 
For full list of syscalls:

/sys/src/9/port/systab.h
/sys/src/libc/9syscall/sys.h
 */

// List of all system calls with sc_ prefix added
typedef int call;
enum call {
	sc__errstr,
	sc__exits,
	sc__fsession,
	sc__fstat,
	sc__fwstat,
	sc__mount,
	sc__nsec,
	sc__read,
	sc__stat,
	sc__wait,
	sc__write,
	sc__wstat,
	sc_alarm,
	sc_await,
	sc_bind,
	sc_brk_,
	sc_chdir,
	sc_close,
	sc_create,
	sc_dup,
	sc_errstr,
	sc_exec,
	sc_fauth,
	sc_fd2path,
	sc_fstat,
	sc_fversion,
	sc_fwstat,
	sc_mount,
	sc_noted,
	sc_notify,
	sc_open,
	sc_oseek,
	sc_pipe,
	sc_pread,
	sc_pwrite,
	sc_remove,
	sc_rendezvous,
	sc_rfork,
	sc_seek,
	sc_segattach,
	sc_segbrk,
	sc_segdetach,
	sc_segflush,
	sc_segfree,
	sc_semacquire,
	sc_semrelease,
	sc_sleep,
	sc_stat,
	sc_sysr1,
	sc_tsemacquire,
	sc_unmount,
	sc_wstat
};

// Structure to track state of system calling
typedef struct caller caller;
struct caller
{
	call		c;			// System call in use
	char*		name;		// Real name of syscall
	int			round;	// Last run executed
};

/* == Function prototypes == */

// input.c
void* mkinput(caller);

#endif
