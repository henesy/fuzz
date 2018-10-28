#ifndef FUZZ_H
#define FUZZ_H
#include "list.h"

/* 
For full list of syscalls:

If systab doesn't exist, do: cd /sys/src/9/port && mk
/sys/src/9/port/systab.h
/sys/src/libc/9syscall/sys.h
/sys/include/libc.h:537
*/

// User space syscall definitions as per libc.h with sc_ prefix added
typedef int call;
enum call {
sc_exits	,		//	_exits(char*);
sc_abort	,		//	abort(void);
sc_access	,		//	access(char*, int);
sc_alarm	,		//	alarm(ulong);
sc_await	,		//	await(char*, int);
sc_bind	,		//	bind(char*, char*, int);
sc_brk	,		//	brk(void*);
sc_chdir	,		//	chdir(char*);
sc_close	,		//	close(int);
sc_create	,		//	create(char*, int, ulong);
sc_dup	,		//	dup(int, int);
sc_errstr	,		//	errstr(char*, uint);
sc_exec	,		//	exec(char*, char*[]);
sc_execl	,		//	execl(char*, ...);
sc_fork	,		//	fork(void);
sc_rfork	,		//	rfork(int);
sc_fauth	,		//	fauth(int, char*);
sc_fstat	,		//	fstat(int, uchar*, int);
sc_fwstat	,		//	fwstat(int, uchar*, int);
sc_fversion,		//	fversion(int, int, char*, int);
sc_mount	,		//	mount(int, int, char*, int, char*);
sc_unmount,		//	unmount(char*, char*);
sc_noted	,		//	noted(int);
sc_notify	,		//	notify(void(*)(void*, char*));
sc_open	,		//	open(char*, int);
sc_fd2path,		//	fd2path(int, char*, int);
sc_pipe	,		//	pipe(int*);
sc_pread	,		//	pread(int, void*, long, vlong);
sc_preadv,		//	preadv(int, IOchunk*, int, vlong);
sc_pwrite	,		//	pwrite(int, void*, long, vlong);
sc_pwritev,		//	pwritev(int, IOchunk*, int, vlong);
sc_read	,		//	read(int, void*, long);
sc_readn	,		//	readn(int, void*, long);
sc_readv	,		//	readv(int, IOchunk*, int);
sc_remove,		//	remove(char*);
sc_sbrk	,		//	sbrk(ulong);
sc_oseek	,		//	oseek(int, long, int);
sc_seek,			//	seek(int, vlong, int);
sc_segattach,		//	segattach(int, char*, void*, ulong);
sc_segbrk	,		//	segbrk(void*, void*);
sc_segdetach,		//	segdetach(void*);
sc_segflush,		//	segflush(void*, ulong);
sc_segfree,		//	segfree(void*, ulong);
sc_semacquire,	//	semacquire(long*, int);
sc_semrelease	,	//	semrelease(long*, long);
sc_sleep,			//	sleep(long);
sc_stat,			//	stat(char*, uchar*, int);
sc_tsemacquire,	//	tsemacquire(long*, ulong);
sc_wait,			//	wait(void);
sc_waitpid,		//	waitpid(void);
sc_write,			//	write(int, void*, long);
sc_writev,			//	writev(int, IOchunk*, int);
sc_wstat,			//	wstat(char*, uchar*, int);
sc_rendezvous,	//	rendezvous(void*, void*);
sc_dirstat,		//	dirstat(char*);
sc_dirfstat,		//	dirfstat(int);
sc_dirwstat,		//	dirwstat(char*, Dir*);
sc_dirfwstat,		//	dirfwstat(int, Dir*);
sc_dirread,		//	dirread(int, Dir**);
sc_nulldir,		//	nulldir(Dir*);
sc_dirreadall,		//	dirreadall(int, Dir**);
sc_getpid	,		//	getpid(void);
sc_getppid,		//	getppid(void);
sc_rerrstr,		//	rerrstr(char*, uint);
sc_sysname,		//	sysname(void);
sc_werrstr		//	werrstr(char*, ...);
};

// Structure to track state of system calling
typedef struct caller caller;
struct caller
{
	call			c;			// System call in use
	char*		name;		// Real name of syscall
	int			round;		// Last run executed
	List			inputs;
};

/* == Function prototypes == */

// input.c
void* mkinput(caller);

#endif
