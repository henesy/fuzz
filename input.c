#include "fuzz.h"

// Procedurally generate input to syscall
void
fuzz(caller *sc)
{

	// seed srand from current seed
	srand(sc->seed);

	// increment the round counter
	(sc->round)++;

	// TODO
	switch(sc->c) {
		case sc_exits :			//	_exits(char*);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			exits( *(char**)lget(&(sc->inputs), 0) );

			break;
		case sc_abort :			//	abort(void);
			dolog("!! Someone called abort, don't do that.\n");
			/* NOPE
			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			abort();
			*/

			break;
		case sc_access :		//	access(char* : int);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			access(	*(char**)lget(&(sc->inputs), 0),
				*(int*)lget(&(sc->inputs), 1) );

			break;
		case sc_alarm :			//	alarm(ulong);
			// mutate the input
			mut_ulong((ulong*)lget(&(sc->inputs), 0), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			alarm( *(ulong*)lget(&(sc->inputs), 0) );

			break;
		case sc_await :			//	await(char* : int);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			await(	*(char**)lget(&(sc->inputs), 0),
				*(int*)lget(&(sc->inputs), 1) );

			break;
		case sc_bind :			//	bind(char* : char* : int);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);
			mut_charstar((char**)lget(&(sc->inputs), 1), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 2), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			bind(	*(char**)lget(&(sc->inputs), 0),
				*(char**)lget(&(sc->inputs), 1),
				*(int*)lget(&(sc->inputs), 2) );

			break;
		case sc_brk :			//	brk(void*);
			break;
		case sc_chdir :			//	chdir(char*);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			chdir( *(char**)lget(&(sc->inputs), 0) );

			break;
		case sc_close :			//	close(int);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			close(*(int*)lget(&(sc->inputs), 0));

			break;
		case sc_create :		//	create(char* : int : ulong);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 1), &sc->round);
			mut_ulong((ulong*)lget(&(sc->inputs), 2), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			create(	*(char**)lget(&(sc->inputs), 0),
				*(int*)lget(&(sc->inputs), 1),
				*(ulong*)lget(&(sc->inputs), 2) );

			break;
		case sc_dup :			//	dup(int : int);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dup(	*(int*)lget(&(sc->inputs), 0),
				*(int*)lget(&(sc->inputs), 1));

			break;
		case sc_errstr :		//	errstr(char* : uint);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);
			mut_uint((uint*)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			errstr(	*(char**)lget(&(sc->inputs), 0),
				*(uint*)lget(&(sc->inputs), 1) );

			break;
		case sc_exec :			//	exec(char* : char*[]);
			//TODO - mut_char_star_arr not implemented
			exits("SYSCALL NOT IMPLEMENTED");
			break;
		case sc_execl :			//	execl(char* : ...);
			//TODO - not sure what to do with variable # of parameters
			exits("SYSCALL NOT IMPLEMENTED");
			break;
		case sc_fork :			//	fork(void);
			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			fork();

			break;
		case sc_rfork :			//	rfork(int);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			rfork(*(int*)lget(&(sc->inputs), 0));

			break;
		case sc_fauth :			//	fauth(int : char*);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_charstar((char**)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			fauth(	*(int*)lget(&(sc->inputs), 0),
				*(char**)lget(&(sc->inputs), 1) );

			break;
		case sc_fstat :			//	fstat(int : uchar* : int);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_ucharstar((unsigned char**)lget(&(sc->inputs), 1), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 2), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			fstat(	*(int*)lget(&(sc->inputs), 0),
				*(unsigned char**)lget(&(sc->inputs), 1),
				*(int*)lget(&(sc->inputs), 2) );

			break;
		case sc_fwstat :		//	fwstat(int : uchar* : int);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_ucharstar((unsigned char**)lget(&(sc->inputs), 1), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 2), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			fwstat(	*(int*)lget(&(sc->inputs), 0),
				*(unsigned char**)lget(&(sc->inputs), 1),
				*(int*)lget(&(sc->inputs), 2) );

			break;
		case sc_fversion :		//	fversion(int : int : char* : int);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 1), &sc->round);
			mut_charstar((char**)lget(&(sc->inputs), 2), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 3), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			fversion(	*(int*)lget(&(sc->inputs), 0),
					*(int*)lget(&(sc->inputs), 1),
					*(char**)lget(&(sc->inputs), 2),
					*(int*)lget(&(sc->inputs), 3) );

			break;
		case sc_mount :			//	mount(int : int : char* : int : char*);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 1), &sc->round);
			mut_charstar((char**)lget(&(sc->inputs), 2), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 3), &sc->round);
			mut_charstar((char**)lget(&(sc->inputs), 4), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			mount(	*(int*)lget(&(sc->inputs), 0),
				*(int*)lget(&(sc->inputs), 1),
				*(char**)lget(&(sc->inputs), 2),
				*(int*)lget(&(sc->inputs), 3),
				*(char**)lget(&(sc->inputs), 4) );

			break;
		case sc_unmount :		//	unmount(char* : char*);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);
			mut_charstar((char**)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			unmount(*(char**)lget(&(sc->inputs), 0),
				*(char**)lget(&(sc->inputs), 1) );

			break;
		case sc_noted :			//	noted(int);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			noted(*(int*)lget(&(sc->inputs), 0));

			break;
		case sc_notify :		//	notify(void(*)(void* : char*));
			//TODO - this sc takes a function pointer, we don't have infrastructure for that
			exits("SYSCALL NOT IMPLEMENTED");
			break;
		case sc_open :			//	open(char* : int);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			open(	*(char**)lget(&(sc->inputs), 0),
				*(int*)lget(&(sc->inputs), 1) );

			break;
		case sc_fd2path :		//	fd2path(int : char* : int);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_charstar((char**)lget(&(sc->inputs), 1), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 2), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			fd2path(*(int*)lget(&(sc->inputs), 0),
				*(char**)lget(&(sc->inputs), 1),
				*(int*)lget(&(sc->inputs), 2) );

			break;
		case sc_pipe :			//	pipe(int*);
			//TODO - this sc takes an int pointer, we don't have infrastructure for that
			exits("SYSCALL NOT IMPLEMENTED");
			break;
		case sc_pread :			//	pread(int : void* : long : vlong);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_voidstar((void**)lget(&(sc->inputs), 1), &sc->round);
			mut_long((long*)lget(&(sc->inputs), 2), &sc->round);
			mut_vlong((long long*)lget(&(sc->inputs), 3), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			pread(	*(int*)lget(&(sc->inputs), 0),
				*(void**)lget(&(sc->inputs), 1),
				*(long*)lget(&(sc->inputs), 2),
				*(long long*)lget(&(sc->inputs), 3) );

			break;
		case sc_preadv :		//	preadv(int : IOchunk* : int : vlong);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_IOchunkstar((IOchunk**)lget(&(sc->inputs), 1), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 2), &sc->round);
			mut_vlong((long long*)lget(&(sc->inputs), 3), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			preadv(	*(int*)lget(&(sc->inputs), 0),
				*(IOchunk**)lget(&(sc->inputs), 1),
				*(int*)lget(&(sc->inputs), 2),
				*(long long*)lget(&(sc->inputs), 3) );

			break;
		case sc_pwrite :		//	pwrite(int : void* : long : vlong);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_voidstar((void**)lget(&(sc->inputs), 1), &sc->round);
			mut_long((long*)lget(&(sc->inputs), 2), &sc->round);
			mut_vlong((long long*)lget(&(sc->inputs), 3), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			pwrite(	*(int*)lget(&(sc->inputs), 0),
				*(void**)lget(&(sc->inputs), 1),
				*(long*)lget(&(sc->inputs), 2),
				*(long long*)lget(&(sc->inputs), 3) );

			break;
		case sc_pwritev :		//	pwritev(int : IOchunk* : int : vlong);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_IOchunkstar((IOchunk**)lget(&(sc->inputs), 1), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 2), &sc->round);
			mut_vlong((long long*)lget(&(sc->inputs), 3), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			pwritev(*(int*)lget(&(sc->inputs), 0),
				*(IOchunk**)lget(&(sc->inputs), 1),
				*(int*)lget(&(sc->inputs), 2),
				*(long long*)lget(&(sc->inputs), 3) );

			break;
		case sc_read :			//	read(int : void* : long);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), sc->round);
			mut_voidstar((void**)lget(&(sc->inputs), 1), sc->round);
			mut_long((long*)lget(&(sc->inputs), 2), sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			read(	*(int*)lget(&(sc->inputs), 0),
				*(void**)lget(&(sc->inputs), 1),
				*(long*)lget(&(sc->inputs), 2) );

			break;
		case sc_readn :			//	readn(int : void* : long);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_voidstar((void**)lget(&(sc->inputs), 1), &sc->round);
			mut_long((long*)lget(&(sc->inputs), 2), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			readn(	*(int*)lget(&(sc->inputs), 0),
				*(void**)lget(&(sc->inputs), 1),
				*(long*)lget(&(sc->inputs), 2) );

			break;
		case sc_readv :			//	readv(int : IOchunk* : int);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_IOchunkstar((IOchunk**)lget(&(sc->inputs), 1), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 2), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			readv(	*(int*)lget(&(sc->inputs), 0),
				*(IOchunk**)lget(&(sc->inputs), 1),
				*(int*)lget(&(sc->inputs), 2) );

			break;
		case sc_remove :		//	remove(char*);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			remove( *(char**)lget(&(sc->inputs), 0) );

			break;
		case sc_sbrk :			//	sbrk(ulong);
			// mutate the input
			mut_ulong((ulong*)lget(&(sc->inputs), 0), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			sbrk( *(ulong*)lget(&(sc->inputs), 0) );

			break;
		case sc_oseek :			//	oseek(int : long : int);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_long((long*)lget(&(sc->inputs), 1), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 2), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			oseek(	*(int*)lget(&(sc->inputs), 0),
				*(long*)lget(&(sc->inputs), 1),
				*(int*)lget(&(sc->inputs), 2) );

			break;
		case sc_seek :			//	seek(int : vlong : int);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_vlong((long long*)lget(&(sc->inputs), 1), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 2), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			seek(	*(int*)lget(&(sc->inputs), 0),
				*(long long*)lget(&(sc->inputs), 1),
				*(int*)lget(&(sc->inputs), 2) );

			break;
		case sc_segattach :		//	segattach(int : char* : void* : ulong);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_charstar((char**)lget(&(sc->inputs), 1), &sc->round);
			mut_voidstar((void**)lget(&(sc->inputs), 2), &sc->round);
			mut_ulong((unsigned long*)lget(&(sc->inputs), 3), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			segattach(	*(int*)lget(&(sc->inputs), 0),
					*(char**)lget(&(sc->inputs), 1),
					*(void**)lget(&(sc->inputs), 2),
					*(unsigned long*)lget(&(sc->inputs), 3) );

			break;
		case sc_segbrk	 :		//	segbrk(void* : void*);
			// mutate the input
			mut_voidstar((void**)lget(&(sc->inputs), 0), &sc->round);
			mut_voidstar((void**)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			segbrk(	*(void**)lget(&(sc->inputs), 0),
				*(void**)lget(&(sc->inputs), 1) );

			break;
		case sc_segdetach :		//	segdetach(void*);
			// mutate the input
			mut_voidstar((void**)lget(&(sc->inputs), 0), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			segdetach( *(void**)lget(&(sc->inputs), 0) );

			break;
		case sc_segflush :		//	segflush(void* : ulong);
			// mutate the input
			mut_voidstar((void**)lget(&(sc->inputs), 0), &sc->round);
			mut_ulong((unsigned long*)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			segflush(	*(void**)lget(&(sc->inputs), 0),
					*(unsigned long*)lget(&(sc->inputs), 1) );

			break;
		case sc_segfree :		//	segfree(void* : ulong);
			// mutate the input
			mut_voidstar((void**)lget(&(sc->inputs), 0), &sc->round);
			mut_ulong((unsigned long*)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			segfree(*(void**)lget(&(sc->inputs), 0),
				*(unsigned long*)lget(&(sc->inputs), 1) );

			break;
		case sc_semacquire :		//	semacquire(long* : int);
			// mutate the input
			mut_longstar((long**)lget(&(sc->inputs), 0), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			semacquire(	*(long**)lget(&(sc->inputs), 0),
					*(int*)lget(&(sc->inputs), 1) );

			break;
		case sc_semrelease :		//	semrelease(long* : long);
			// mutate the input
			mut_longstar((long**)lget(&(sc->inputs), 0), &sc->round);
			mut_long((long*)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			semrelease(	*(long**)lget(&(sc->inputs), 0),
					*(long*)lget(&(sc->inputs), 1) );

			break;
		case sc_sleep :			//	sleep(long);
			// mutate the input
			mut_long((long*)lget(&(sc->inputs), 0), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			sleep( *(long*)lget(&(sc->inputs), 0) );

			break;
		case sc_stat :			//	stat(char* : uchar* : int);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);
			mut_ucharstar((unsigned char**)lget(&(sc->inputs), 1), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 2), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			stat(	*(char**)lget(&(sc->inputs), 0),
				*(unsigned char**)lget(&(sc->inputs), 1),
				*(int*)lget(&(sc->inputs), 2) );

			break;
		case sc_tsemacquire :		//	tsemacquire(long* : ulong);
			// mutate the input
			mut_longstar((long**)lget(&(sc->inputs), 0), &sc->round);
			mut_ulong((ulong*)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			tsemacquire(	*(long**)lget(&(sc->inputs), 0),
					*(ulong*)lget(&(sc->inputs), 1) );

			break;
		case sc_wait :			//	wait(void);
			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			wait();

			break;
		case sc_waitpid :		//	waitpid(void);
			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			waitpid();

			break;
		case sc_write :			//	write(int : void* : long);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_voidstar((void**)lget(&(sc->inputs), 1), &sc->round);
			mut_long((long*)lget(&(sc->inputs), 2), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			write(	*(int*)lget(&(sc->inputs), 0),
				*(void**)lget(&(sc->inputs), 1),
				*(long*)lget(&(sc->inputs), 2) );

			break;
		case sc_writev :		//	writev(int : IOchunk* : int);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_IOchunkstar((IOchunk**)lget(&(sc->inputs), 1), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 2), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			writev(	*(int*)lget(&(sc->inputs), 0),
				*(IOchunk**)lget(&(sc->inputs), 1),
				*(int*)lget(&(sc->inputs), 2) );

			break;
		case sc_wstat :			//	wstat(char* : uchar* : int);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);
			mut_ucharstar((unsigned char**)lget(&(sc->inputs), 1), &sc->round);
			mut_int((int*)lget(&(sc->inputs), 2), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			wstat(	*(char**)lget(&(sc->inputs), 0),
				*(unsigned char**)lget(&(sc->inputs), 1),
				*(int*)lget(&(sc->inputs), 2) );

			break;
		case sc_rendezvous :		//	rendezvous(void* : void*);
			// mutate the input
			mut_voidstar((void**)lget(&(sc->inputs), 0), &sc->round);
			mut_voidstar((void**)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			rendezvous(	*(void**)lget(&(sc->inputs), 0),
					*(void**)lget(&(sc->inputs), 1) );

			break;
		case sc_dirstat :		//	dirstat(char*);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dirstat( *(char**)lget(&(sc->inputs), 0) );

			break;
		case sc_dirfstat :		//	dirfstat(int);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dirfstat(*(int*)lget(&(sc->inputs), 0));

			break;
		case sc_dirwstat :		//	dirwstat(char* : Dir*);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);
			mut_dirstar((Dir**)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dirwstat(	*(char**)lget(&(sc->inputs), 0),
					*(Dir**)lget(&(sc->inputs), 1) );

			break;
		case sc_dirfwstat :		//	dirfwstat(int : Dir*);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_dirstar((Dir**)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dirfwstat(	*(int*)lget(&(sc->inputs), 0),
					*(Dir**)lget(&(sc->inputs), 1) );

			break;
		case sc_dirread :		//	dirread(int : Dir**);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_dirstar_star((Dir***)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dirread(	*(int*)lget(&(sc->inputs), 0),
					*(Dir***)lget(&(sc->inputs), 1) );

			break;
		case sc_nulldir :		//	nulldir(Dir*);
			// mutate the input
			mut_dirstar((Dir**)lget(&(sc->inputs), 0), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			nulldir( *(Dir**)lget(&(sc->inputs), 0) );

			break;
		case sc_dirreadall :		//	dirreadall(int : Dir**);
			// mutate the input
			mut_int((int*)lget(&(sc->inputs), 0), &sc->round);
			mut_dirstar_star((Dir***)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dirreadall(	*(int*)lget(&(sc->inputs), 0),
					*(Dir***)lget(&(sc->inputs), 1) );

			break;
		case sc_getpid :		//	getpid(void);
			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			getpid();

			break;
		case sc_getppid	:		//	getppid(void);
			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			getppid();

			break;
		case sc_rerrstr :		//	rerrstr(char* : uint);
			// mutate the input
			mut_charstar((char**)lget(&(sc->inputs), 0), &sc->round);
			mut_uint((uint*)lget(&(sc->inputs), 1), &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			rerrstr(*(char**)lget(&(sc->inputs), 0),
				*(uint*)lget(&(sc->inputs), 1) );

			break;
		case sc_sysname :		//	sysname(void);
			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			sysname();

			break;
		case sc_werrstr :		//	werrstr(char* : ...);
			//TODO - not sure what to do with variable # of parameters
			exits("SYSCALL NOT IMPLEMENTED");
			break;
		default:
			exits("Unknown system call");
	}
}

// Logs the syscall arguments
void
log_call(caller *sc)
{
	dolog("\nSystem Call: %s\n", sc->name);
	// legacy since this is printed elsewhere
	//dolog("\n\tRound #: %d\n", sc->round);
	dolog("Arguments:\n");
	int x;
	for (x = 0; x < (sc->inputs.size); x++) {
		t_type* ele = lget(&(sc->inputs), x);

		dolog("\t\t%s : ", callnames[ele->t]);

		switch(ele->t) {
			case t_int :
				dolog("t_int: %d\n", *(int*) ele->var);
				break;
			case t_uint :
				dolog("t_uint: %d\n", *(unsigned int*) ele->var);
				break;
			case t_long :
				dolog("t_long: %ld\n", *(long*) ele->var);
				break;
			case t_ulong :
				dolog("t_ulong: %lud\n", *(unsigned long*) ele->var);
				break;
			case t_vlong :
				dolog("t_vlong: %lld\n", *(long long*) ele->var);
				break;
			case t_longS :
				dolog("t_longS: %ld\n", *(long*) ele->var);
				break;
			case t_DirS :  //TODO : verify that this works; compiler warns against
				// dolog("t_DirS: %s\n", (Dir*) ele->var);
				break;
			case t_charS :
				// TODO -- segfaults
				// dolog("t_charS: %s\n", *(char**) ele->var);
				break;
			case t_charSArr :
				//dolog("t_charSArr: %s\n", (char**) ele->var);
				break;
			case t_char :
				dolog("t_char: %c\n", *(char*) ele->var);
				break;
			case t_uchar :
				dolog("t_uchar: %c\n", *(unsigned char*) ele->var);
				break;
			default :
				exits("Unknown input variable type!");
		}
		dolog("\n");
	}
}

// Syncs the disk in hjfs
void
hjsync()
{
	// open file and write to sync disk
	int hjfs = open("/srv/hjfs.cmd", OWRITE);
	fprint(hjfs, "sync\n");
	close(hjfs);
}

// Init callnames here, is extern in fuzz.h
char *callnames[NCALLS]= {
"_exits",
"abort",
"access",
"alarm",
"await",
"bind",
"brk",
"chdir",
"close",
"create",
"dup",
"errstr",
"exec",
"execl",
"fork",
"rfork",
"fauth",
"fstat",
"fwstat",
"fversion",
"mount",
"unmount",
"noted",
"notify",
"open",
"fd2path",
"pipe",
"pread",
"preadv",
"pwrite",
"pwritev",
"read",
"readn",
"readv",
"remove",
"sbrk",
"oseek",
"seek",
"segattach",
"segbrk",
"segdetach",
"segflush",
"segfree",
"semacquire",
"semrelease",
"sleep",
"stat",
"tsemacquire",
"wait",
"waitpid",
"write",
"writev",
"wstat",
"rendezvous",
"dirstat",
"dirfstat",
"dirwstat",
"dirfwstat",
"dirread",
"nulldir",
"dirreadall",
"getpid",
"getppid",
"rerrstr",
"sysname",
"werrstr"
};

// Init callnames here, is extern in fuzz.h
char *typenames[NTYPES]= {
"int",
"long",
"Dir*",
"char*"
};
