#ifndef FUZZ_H
#define FUZZ_H

#include <u.h>
#include <libc.h>
#include <bio.h>

#include "list.h"
#include "mutate.h"


// Macros
// Sysfatal if not syscall not implemented
#define noimpl() sysfatal("Error: Syscall not implemented!");

// Max signed int value
#define MAXINT 2147483647

// Number of calls in enum calls
#define NCALLS 67
#define NTYPES 16

// Global variables
// In main.c
extern	Biobuf*	logbp;
extern	Biobuf*	hjbp;
extern	Lock	loglck;
extern	Lock	rnglck;

/*
For full list of syscalls:

If systab doesn't exist → cd /sys/src/9/port && mk

/sys/src/9/port/systab.h
/sys/src/libc/9syscall/sys.h
/sys/include/libc.h:537
*/

// User space syscall definitions as per libc.h with sc_ prefix added
typedef int call;
enum call {
sc__exits,		// unused -- here for offset
sc_abort	,	//	abort(void);
sc_access	,	//	access(char*, int);
sc_alarm	,	//	alarm(ulong);
sc_await	,	//	await(char*, int);
sc_bind	,		//	bind(char*, char*, int);
sc_brk	,		//	brk(void*);
sc_chdir	,	//	chdir(char*);
sc_close	,	//	close(int);
sc_create	,	//	create(char*, int, ulong);
sc_dup	,		//	dup(int, int);
sc_errstr	,	//	errstr(char*, uint);
sc_exec	,		//	exec(char*, char*[]);
sc_execl	,	//	execl(char*, ...);
sc_exits	,	//	_exits(char*); // unused
sc_fork	,		//	fork(void);
sc_rfork	,	//	rfork(int);
sc_fauth	,	//	fauth(int, char*);
sc_fstat	,	//	fstat(int, uchar*, int);
sc_fwstat	,	//	fwstat(int, uchar*, int);
sc_fversion,	//	fversion(int, int, char*, int);
sc_mount	,	//	mount(int, int, char*, int, char*);
sc_unmount,		//	unmount(char*, char*);
sc_noted	,	//	noted(int);
sc_notify	,	//	notify(void(*)(void*, char*));
sc_open	,		//	open(char*, int);
sc_fd2path,		//	fd2path(int, char*, int);
sc_pipe	,		//	pipe(int*);
sc_pread	,	//	pread(int, void*, long, vlong);
sc_preadv,		//	preadv(int, IOchunk*, int, vlong);
sc_pwrite	,	//	pwrite(int, void*, long, vlong);
sc_pwritev,		//	pwritev(int, IOchunk*, int, vlong);
sc_read	,		//	read(int, void*, long);
sc_readn	,	//	readn(int, void*, long);
sc_readv	,	//	readv(int, IOchunk*, int);
sc_remove,		//	remove(char*);
sc_sbrk	,		//	sbrk(ulong);
sc_oseek	,	//	oseek(int, long, int);
sc_seek,		//	seek(int, vlong, int);
sc_segattach,	//	segattach(int, char*, void*, ulong);
sc_segbrk	,	//	segbrk(void*, void*);
sc_segdetach,	//	segdetach(void*);
sc_segflush,	//	segflush(void*, ulong);
sc_segfree,		//	segfree(void*, ulong);
sc_semacquire,	//	semacquire(long*, int);
sc_semrelease,	//	semrelease(long*, long);
sc_sleep,		//	sleep(long);
sc_stat,		//	stat(char*, uchar*, int);
sc_tsemacquire,	//	tsemacquire(long*, ulong);
sc_wait,		//	wait(void);
sc_waitpid,		//	waitpid(void);
sc_write,		//	write(int, void*, long);
sc_writev,		//	writev(int, IOchunk*, int);
sc_wstat,		//	wstat(char*, uchar*, int);
sc_rendezvous,	//	rendezvous(void*, void*);
sc_dirstat,		//	dirstat(char*);
sc_dirfstat,	//	dirfstat(int);
sc_dirwstat,	//	dirwstat(char*, Dir*);
sc_dirfwstat,	//	dirfwstat(int, Dir*);
sc_dirread,		//	dirread(int, Dir**);
sc_nulldir,		//	nulldir(Dir*);
sc_dirreadall,	//	dirreadall(int, Dir**);
sc_getpid	,	//	getpid(void);
sc_getppid,		//	getppid(void);
sc_rerrstr,		//	rerrstr(char*, uint);
sc_sysname,		//	sysname(void);
sc_werrstr		//	werrstr(char*, ...);
};

// Enum to track types of inputs
typedef int type;
enum type {
t_int,          // int
t_intS,         // int pointer
t_uint,         // unsigned int
t_IOchunkS,     // IOChunkS pointer
t_long,         // long
t_longS,        // long pointer
t_ulong,        // unsigned long
t_vlong,        // long long
t_DirS,         // directory pointer
t_DirSS,        // director pointer to string of chars
t_char,         // char
t_uchar,        // unsigned char
t_ucharS,       // unsigned char pointer
t_charS,        // string
t_charSArr,     // char pointer array
t_void,         // void type
t_voidS         // void pointer type
};

// Structure to track an instance of a given type
typedef struct t_type t_type;
struct t_type
{
	void*	var;	// Variable to track
	type	t;		// Type of the variable to cast to
};

// Type names table -- see: input.c
extern char *typenames[NTYPES];

// User space system call names table -- see: input.c
extern char *callnames[NCALLS];

// Structure to track state of system calling
typedef struct caller caller;
struct caller
{
	call		c;			// System call in use
	char*		name;		// Real name of syscall
	int			round;		// Last run executed
	int			seed;		// Seed call was initialized with
	List		inputs;		// List of input types in order from left→right
};

// Index of system calls -- one for each enum'd system call
caller syscalls[NCALLS];

/* == Function prototypes == */

// input.c
void	fuzz(caller*);
void	hjsync(void);
void	log_call(caller*);

// inlist.c
List*	mkinlist(List*, call);

// list.c → See list.h

// mutate.c → See mutate.h

// main.c
void	dolog(char*, ...);
void	debug(char*, ...);
int		rng(void);

#endif
