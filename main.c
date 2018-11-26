#include "fuzz.h"

// Global variables are bad
int		logfd = -1; // fd of the log file, initialized in main
Lock	loglck;		// Lock for logger
Lock	rnglck;		// Lock for rng

// Commandline usage warning
void
usage(void)
{
	fprint(2, "usage: %s [-s seed] [-n rounds] calls\n", argv0);
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

// Perform a debug mode print (if built with -DDEBUG)
void
debug(char *fmt, ...)
{
	#ifdef DEBUG
	va_list args;
	va_start(args, fmt);

	vfprint(1, fmt, args);

	va_end(args);
	#endif
}

// Thread-safe sleepable random number generator
int
rng(void)
{
	ulong x;
	lock(&rnglck);
	// Generate a number: 0 ≤ x ≤ MAXINT
	x = nrand(MAXINT);
	//debug("DEBUG: Generated num is: %d\n", x);
	unlock(&rnglck);
	return x;
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
	char* arg;
	long fuzz_seed = truerand();

	ARGBEGIN{
		case 'n':
			// Number of rounds to iterate fuzzing for
			arg = ARGF();
			if(arg == nil)
				usage();
			nrounds = atoi(arg);
			break;
		case 's':
			// Seed to fuzz from
			arg = ARGF();
			if(arg == nil)
				usage();
			fuzz_seed = atol(arg);
			break;
		default:
			usage();
	}ARGEND

	// Initialize the table of all system calls
	initsctable();
	
	// If no system calls are specified, throw usage()
	if(argc == 0)
		usage();

	// If the call name '?' is specified as the first argument, print all call names
	if(strcmp(*argv, "?") == 0){
		int i;
		for(i = 0; i < NCALLS; i++)
			print("%s\n", callnames[i]);
		exits("Listing all known system calls");
	}
	
	// Acquire a list of calls specified by spaces (fuzz -n 1 read write seek)
	for(;*argv;argv++){
		int index;
		if((index = name2index(*argv)) > 0){
		
			debug("DEBUG index %d matched to \"%s\"\n", index, *argv);
			
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

	srand(fuzz_seed);
	dolog("== Seed Value: %d ==\n", fuzz_seed);

	// Operate for the desired number of rounds, -1 is infinite
	for(i = 0; i < nrounds || nrounds < 0; i++){
		int j;
		dolog("== Begin round %d ==\n", i);
		
		debug("DEBUG: i: %d nrounds: %d\n", i, nrounds);
		
		for(j = 0; j < tofuzz.size; j++){
		
			debug("DEBUG: tofuzz.size: %d\n", tofuzz.size);
			
			caller *fcall = (caller*) lget(&tofuzz, j);
			dolog("­­ Fuzzing: %s ­­\n", fcall->name);
			
			fuzz(fcall); // Fuzz, syncs the disk
		}	
	}

	fprint(2, "Fuzz ending…\n");
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
		if(strcmp(syscalls[i].name, name) == 0)
			return i;
	}
	return -1;
}
