#include "fuzz.h"

// Global variables are bad
int		logfd = -1; // fd of the log file, initialized in main
Lock	loglck;		// Lock for logger

// Commandline usage warning
void
usage(void)
{
	fprint(2, "usage: %s [-n rounds] calls\n", argv0);
	exits("usage");
}

// Perform locked logging operation -- wraps print
void
dolog(char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	lock(&loglck);
	vfprint(logfd, fmt, args);
	unlock(&loglck);

	va_end(args);
}

/* Prototypes */
void	initsctable(void);
int		name2index(char*);


// A kernel fuzzer for the Plan 9 kernel
void
main(int argc, char *argv[])
{
	int nrounds = -1, i;
	List tofuzz = mklist() ; // List of syscall table ID's to fuzz

	ARGBEGIN{
		case 'n':
			// Number of rounds to iterate fuzzing for
			nrounds = atoi(ARGF());
			break;
		default:
			usage();
	}ARGEND

	// Initialize the table of all system calls
	initsctable();

	// Acquire a list of calls specified by spaces (fuzz -n 1 read write seek)
	for(;*argv;argv++){
		int index;
		if((index = name2index(*argv)) > 0){
			#ifdef DEBUG 
			print("DEBUG index: %d\n", index);
			#endif
			dolog("Loading call: %s\n", *argv);
			ladd(&tofuzz, &syscalls[index]); // Might be dangerous, pls fix
		}else{
			fprint(2, "Error: Invalid system call: %s\n", *argv);
			exits("Encountered invalid syscall");
		}
	}
	
	logfd = create("./fuzz.log", OWRITE, 0777);
	if(logfd < 0){
		fprint(2, "Error: Failed to create/open log file.");
		exits("log file create fail");
	}

	// save so we don't have two different time(0)'s
	int fuzz_seed = time(0);
	srand(fuzz_seed);
	dolog("==Seed Value: %d==\n", fuzz_seed);

	// Operate for the desired number of rounds, -1 is infinite
	for(i = 0; i < nrounds || nrounds < 0; i++){
		int j;
		dolog("== Begin round %d ==\n", i);
		for(j = 0; j < tofuzz.size; j++){
			caller *fcall = (caller*) lget(&tofuzz, j);
			dolog("­­ Fuzzing: %s ­­\n", fcall->name);
			
			fuzz(fcall); // Fuzz, syncs the disk
			/*
			// Someone in here is calling exits inappropriately so forking.
			int pid = rfork(RFFDG|RFREND|RFPROC|RFMEM);
			if(pid == 0){
				// Child
				fuzz(fcall); // Fuzz, syncs the disk
				exits(nil);
			}
			*/
		}	
	}

	close(logfd);
	exits(nil);
}


// Initialize the syscall table -- hopefully deprecated by a lex/yacc builder
void
initsctable(void)
{
	int i;
	for(i = 0; i < NCALLS; i++){
		syscalls[i].c = (call)i;
		syscalls[i].name = callnames[i]; // Pointer points to callnames
		syscalls[i].round = -1;
		syscalls[i].seed = -1;
		mkinlist(&(syscalls[i].inputs), (call)i);
	}
}

// Given a syscall name, return the index it occurs -- or -1 if not found
int
name2index(char* name)
{
	int i;
	for(i = 0; i < NCALLS; i++){
		#ifdef DEBUG
		print("DEBUG cmp %s to %s on %d\n", syscalls[i].name, name, i);
		#endif
		if(strcmp(syscalls[i].name, name) == 0)
			return i;
	}
	return -1;
}
