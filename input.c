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
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			exits( *(char**)((t_type*)lget(&(sc->inputs), 0))->var );

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
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			access(	*(char**)((t_type*)lget(&(sc->inputs), 0))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_alarm :			//	alarm(ulong);
			// mutate the input
			mut_ulong((ulong*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			alarm( *(ulong*)((t_type*)lget(&(sc->inputs), 0))->var );

			break;
		case sc_await :			//	await(char* : int);
			// mutate the input
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			await(	*(char**)((t_type*)lget(&(sc->inputs), 0))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_bind :			//	bind(char* : char* : int);
			// mutate the input
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			bind(	*(char**)((t_type*)lget(&(sc->inputs), 0))->var,
				*(char**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_brk :			//	brk(void*);
			break;
		case sc_chdir :			//	chdir(char*);
			// mutate the input
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			chdir( *(char**)((t_type*)lget(&(sc->inputs), 0))->var );

			break;
		case sc_close :			//	close(int);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			close(*(int*)((t_type*)lget(&(sc->inputs), 0))->var);

			break;
		case sc_create :		//	create(char* : int : ulong);
			// mutate the input
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_ulong((ulong*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			create(	*(char**)((t_type*)lget(&(sc->inputs), 0))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 1))->var,
				*(ulong*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_dup :			//	dup(int : int);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dup(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 1))->var);

			break;
		case sc_errstr :		//	errstr(char* : uint);
			// mutate the input
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_uint((uint*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			errstr(	*(char**)((t_type*)lget(&(sc->inputs), 0))->var,
				*(uint*)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_exec :			//	exec(char* : char*[]);
			//TODO - mut_char_star_arr not implemented
			fprint(2, "Error: Syscall not implemented!\n");
			exits("SYSCALL NOT IMPLEMENTED");
			break;
		case sc_execl :			//	execl(char* : ...);
			//TODO - not sure what to do with variable # of parameters
			fprint(2, "Error: Syscall not implemented!\n");
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
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			rfork(*(int*)((t_type*)lget(&(sc->inputs), 0))->var);

			break;
		case sc_fauth :			//	fauth(int : char*);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			fauth(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(char**)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_fstat :			//	fstat(int : uchar* : int);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_ucharstar((unsigned char**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			fstat(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(unsigned char**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_fwstat :		//	fwstat(int : uchar* : int);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_ucharstar((unsigned char**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			fwstat(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(unsigned char**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_fversion :		//	fversion(int : int : char* : int);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 3))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			fversion(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
					*(int*)((t_type*)lget(&(sc->inputs), 1))->var,
					*(char**)((t_type*)lget(&(sc->inputs), 2))->var,
					*(int*)((t_type*)lget(&(sc->inputs), 3))->var );

			break;
		case sc_mount :			//	mount(int : int : char* : int : char*);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 3))->var, &sc->round);
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 4))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			mount(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 1))->var,
				*(char**)((t_type*)lget(&(sc->inputs), 2))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 3))->var,
				*(char**)((t_type*)lget(&(sc->inputs), 4))->var );

			break;
		case sc_unmount :		//	unmount(char* : char*);
			// mutate the input
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			unmount(*(char**)((t_type*)lget(&(sc->inputs), 0))->var,
				*(char**)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_noted :			//	noted(int);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			noted(*(int*)((t_type*)lget(&(sc->inputs), 0))->var);

			break;
		case sc_notify :		//	notify(void(*)(void* : char*));
			//TODO - this sc takes a function pointer, we don't have infrastructure for that
			fprint(2, "Error: Syscall not implemented!\n");
			exits("SYSCALL NOT IMPLEMENTED");
			break;
		case sc_open :			//	open(char* : int);
			// mutate the input
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			open(	*(char**)((t_type*)lget(&(sc->inputs), 0))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_fd2path :		//	fd2path(int : char* : int);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			fd2path(*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(char**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_pipe :			//	pipe(int*);
			mut_intstar((int**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			log_call(sc);

			hjsync();

			pipe(*(int**)((t_type*)lget(&(sc->inputs), 0))->var);

			break;
		case sc_pread :			//	pread(int : void* : long : vlong);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_voidstar((void**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_long((long*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);
			mut_vlong((long long*)((t_type*)lget(&(sc->inputs), 3))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			pread(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(void**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(long*)((t_type*)lget(&(sc->inputs), 2))->var,
				*(long long*)((t_type*)lget(&(sc->inputs), 3))->var );

			break;
		case sc_preadv :		//	preadv(int : IOchunk* : int : vlong);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_IOchunkstar((IOchunk**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);
			mut_vlong((long long*)((t_type*)lget(&(sc->inputs), 3))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			preadv(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(IOchunk**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 2))->var,
				*(long long*)((t_type*)lget(&(sc->inputs), 3))->var );

			break;
		case sc_pwrite :		//	pwrite(int : void* : long : vlong);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_voidstar((void**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_long((long*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);
			mut_vlong((long long*)((t_type*)lget(&(sc->inputs), 3))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			pwrite(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(void**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(long*)((t_type*)lget(&(sc->inputs), 2))->var,
				*(long long*)((t_type*)lget(&(sc->inputs), 3))->var );

			break;
		case sc_pwritev :		//	pwritev(int : IOchunk* : int : vlong);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_IOchunkstar((IOchunk**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);
			mut_vlong((long long*)((t_type*)lget(&(sc->inputs), 3))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			pwritev(*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(IOchunk**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 2))->var,
				*(long long*)((t_type*)lget(&(sc->inputs), 3))->var );

			break;
		case sc_read :			//	read(int : void* : long);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_voidstar((void**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_long((long*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			read(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(void**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(long*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_readn :			//	readn(int : void* : long);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_voidstar((void**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_long((long*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			readn(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(void**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(long*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_readv :			//	readv(int : IOchunk* : int);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_IOchunkstar((IOchunk**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			readv(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(IOchunk**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_remove :		//	remove(char*);
			// mutate the input
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			remove( *(char**)((t_type*)lget(&(sc->inputs), 0))->var );

			break;
		case sc_sbrk :			//	sbrk(ulong);
			// mutate the input
			mut_ulong((ulong*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			sbrk( *(ulong*)((t_type*)lget(&(sc->inputs), 0))->var );

			break;
		case sc_oseek :			//	oseek(int : long : int);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_long((long*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			oseek(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(long*)((t_type*)lget(&(sc->inputs), 1))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_seek :			//	seek(int : vlong : int);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_vlong((long long*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			seek(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(long long*)((t_type*)lget(&(sc->inputs), 1))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_segattach :		//	segattach(int : char* : void* : ulong);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_voidstar((void**)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);
			mut_ulong((unsigned long*)((t_type*)lget(&(sc->inputs), 3))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			segattach(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
					*(char**)((t_type*)lget(&(sc->inputs), 1))->var,
					*(void**)((t_type*)lget(&(sc->inputs), 2))->var,
					*(unsigned long*)((t_type*)lget(&(sc->inputs), 3))->var );

			break;
		case sc_segbrk	 :		//	segbrk(void* : void*);
			// mutate the input
			mut_voidstar((void**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_voidstar((void**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			segbrk(	*(void**)((t_type*)lget(&(sc->inputs), 0))->var,
				*(void**)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_segdetach :		//	segdetach(void*);
			// mutate the input
			mut_voidstar((void**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			segdetach( *(void**)((t_type*)lget(&(sc->inputs), 0))->var );

			break;
		case sc_segflush :		//	segflush(void* : ulong);
			// mutate the input
			mut_voidstar((void**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_ulong((unsigned long*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			segflush(	*(void**)((t_type*)lget(&(sc->inputs), 0))->var,
					*(unsigned long*)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_segfree :		//	segfree(void* : ulong);
			// mutate the input
			mut_voidstar((void**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_ulong((unsigned long*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			segfree(*(void**)((t_type*)lget(&(sc->inputs), 0))->var,
				*(unsigned long*)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_semacquire :		//	semacquire(long* : int);
			// mutate the input
			mut_longstar((long**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			semacquire(	*(long**)((t_type*)lget(&(sc->inputs), 0))->var,
					*(int*)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_semrelease :		//	semrelease(long* : long);
			// mutate the input
			mut_longstar((long**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_long((long*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			semrelease(	*(long**)((t_type*)lget(&(sc->inputs), 0))->var,
					*(long*)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_sleep :			//	sleep(long);
			// mutate the input
			mut_long((long*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			sleep( *(long*)((t_type*)lget(&(sc->inputs), 0))->var );

			break;
		case sc_stat :			//	stat(char* : uchar* : int);
			// mutate the input
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_ucharstar((unsigned char**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			stat(	*(char**)((t_type*)lget(&(sc->inputs), 0))->var,
				*(unsigned char**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_tsemacquire :		//	tsemacquire(long* : ulong);
			// mutate the input
			mut_longstar((long**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_ulong((ulong*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			tsemacquire(	*(long**)((t_type*)lget(&(sc->inputs), 0))->var,
					*(ulong*)((t_type*)lget(&(sc->inputs), 1))->var );

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
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_voidstar((void**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_long((long*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			write(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(void**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(long*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_writev :		//	writev(int : IOchunk* : int);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_IOchunkstar((IOchunk**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			writev(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
				*(IOchunk**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_wstat :			//	wstat(char* : uchar* : int);
			// mutate the input
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_ucharstar((unsigned char**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);
			mut_int((int*)((t_type*)lget(&(sc->inputs), 2))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			wstat(	*(char**)((t_type*)lget(&(sc->inputs), 0))->var,
				*(unsigned char**)((t_type*)lget(&(sc->inputs), 1))->var,
				*(int*)((t_type*)lget(&(sc->inputs), 2))->var );

			break;
		case sc_rendezvous :		//	rendezvous(void* : void*);
			// mutate the input
			mut_voidstar((void**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_voidstar((void**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			rendezvous(	*(void**)((t_type*)lget(&(sc->inputs), 0))->var,
					*(void**)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_dirstat :		//	dirstat(char*);
			// mutate the input
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dirstat( *(char**)((t_type*)lget(&(sc->inputs), 0))->var );

			break;
		case sc_dirfstat :		//	dirfstat(int);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dirfstat(*(int*)((t_type*)lget(&(sc->inputs), 0))->var);

			break;
		case sc_dirwstat :		//	dirwstat(char* : Dir*);
			// mutate the input
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_dirstar((Dir**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dirwstat(	*(char**)((t_type*)lget(&(sc->inputs), 0))->var,
					*(Dir**)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_dirfwstat :		//	dirfwstat(int : Dir*);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_dirstar((Dir**)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dirfwstat(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
					*(Dir**)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_dirread :		//	dirread(int : Dir**);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_dirstar_star((Dir***)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dirread(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
					*(Dir***)((t_type*)lget(&(sc->inputs), 1))->var );

			break;
		case sc_nulldir :		//	nulldir(Dir*);
			// mutate the input
			mut_dirstar((Dir**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			nulldir( *(Dir**)((t_type*)lget(&(sc->inputs), 0))->var );

			break;
		case sc_dirreadall :		//	dirreadall(int : Dir**);
			// mutate the input
			mut_int((int*)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_dirstar_star((Dir***)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			dirreadall(	*(int*)((t_type*)lget(&(sc->inputs), 0))->var,
					*(Dir***)((t_type*)lget(&(sc->inputs), 1))->var );

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
			mut_charstar((char**)((t_type*)lget(&(sc->inputs), 0))->var, &sc->round);
			mut_uint((uint*)((t_type*)lget(&(sc->inputs), 1))->var, &sc->round);

			// log the variables
			log_call(sc);

			// sync the disk
			hjsync();

			// execute the call
			rerrstr(*(char**)((t_type*)lget(&(sc->inputs), 0))->var,
				*(uint*)((t_type*)lget(&(sc->inputs), 1))->var );

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
			fprint(2, "Error: Syscall not implemented!\n");
			exits("SYSCALL NOT IMPLEMENTED");
			break;
		default:
			fprint(2, "Error: Unknown system call encountered!\n");
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
				fprint(2, "Error: Encountered unknown input variable type!\n");
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
