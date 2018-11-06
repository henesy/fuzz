#include <u.h>
#include <libc.h>
#include "fuzz.h"
#include "mutate.h"

// Procedurally generate input to syscall
void*
mkinput(caller sc)
{
	// TODO
	switch(sc.call) {
		case sc_exits :			//	_exits(char*);
		case sc_abort :			//	abort(void);
		case sc_access :		//	access(char* : int);
		case sc_alarm :			//	alarm(ulong);
		case sc_await :			//	await(char* : int);
		case sc_bind :			//	bind(char* : char* : int);
		case sc_brk :			//	brk(void*);
		case sc_chdir :			//	chdir(char*);
		case sc_close :			//	close(int);
		case sc_create :		//	create(char* : int : ulong);
		case sc_dup :			//	dup(int : int);
		case sc_errstr :		//	errstr(char* : uint);
		case sc_exec :			//	exec(char* : char*[]);
		case sc_execl :			//	execl(char* : ...);
		case sc_fork :			//	fork(void);
		case sc_rfork :			//	rfork(int);
		case sc_fauth :			//	fauth(int : char*);
		case sc_fstat :			//	fstat(int : uchar* : int);
		case sc_fwstat :		//	fwstat(int : uchar* : int);
		case sc_fversion :		//	fversion(int : int : char* : int);
		case sc_mount :			//	mount(int : int : char* : int : char*);
		case sc_unmount :		//	unmount(char* : char*);
		case sc_noted :			//	noted(int);
		case sc_notify :		//	notify(void(*)(void* : char*));
		case sc_open :			//	open(char* : int);
		case sc_fd2path :		//	fd2path(int : char* : int);
		case sc_pipe :			//	pipe(int*);
		case sc_pread :			//	pread(int : void* : long : vlong);
		case sc_preadv :		//	preadv(int : IOchunk* : int : vlong);
		case sc_pwrite :		//	pwrite(int : void* : long : vlong);
		case sc_pwritev :		//	pwritev(int : IOchunk* : int : vlong);
		case sc_read :			//	read(int : void* : long);
		case sc_readn :			//	readn(int : void* : long);
		case sc_readv :			//	readv(int : IOchunk* : int);
		case sc_remove :		//	remove(char*);
		case sc_sbrk :			//	sbrk(ulong);
		case sc_oseek :			//	oseek(int : long : int);
		case sc_seek :			//	seek(int : vlong : int);
		case sc_segattach :		//	segattach(int : char* : void* : ulong);
		case sc_segbrk	 :		//	segbrk(void* : void*);
		case sc_segdetach :		//	segdetach(void*);
		case sc_segflush :		//	segflush(void* : ulong);
		case sc_segfree :		//	segfree(void* : ulong);
		case sc_semacquire :		//	semacquire(long* : int);
		case sc_semrelease :		//	semrelease(long* : long);
		case sc_sleep :			//	sleep(long);
		case sc_stat :			//	stat(char* : uchar* : int);
		case sc_tsemacquire :		//	tsemacquire(long* : ulong);
		case sc_wait :			//	wait(void);
		case sc_waitpid :		//	waitpid(void);
		case sc_write :			//	write(int : void* : long);
		case sc_writev :		//	writev(int : IOchunk* : int);
		case sc_wstat :			//	wstat(char* : uchar* : int);
		case sc_rendezvous :		//	rendezvous(void* : void*);
		case sc_dirstat :		//	dirstat(char*);
		case sc_dirfstat :		//	dirfstat(int);
		case sc_dirwstat :		//	dirwstat(char* : Dir*);
		case sc_dirfwstat :		//	dirfwstat(int : Dir*);
		case sc_dirread :		//	dirread(int : Dir**);
		case sc_nulldir :		//	nulldir(Dir*);
		case sc_dirreadall :		//	dirreadall(int : Dir**);
		case sc_getpid :		//	getpid(void);
		case sc_getppid	:		//	getppid(void);
		case sc_rerrstr :		//	rerrstr(char* : uint);
		case sc_sysname :		//	sysname(void);
		case sc_werrstr :		//	werrstr(char* : ...);
		default :
			#PANIC!
	}
	return nil;
}
