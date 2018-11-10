#include "fuzz.h"

// Global variables are bad
int logfd = -1; // fd of the log file, initialized in main


// Commandline usage warning
void
usage(void)
{
	fprint(2, "usage: %s [-n rounds] calls\n", argv0);
	exits("usage");
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
		if(index = name2index(*argv) > 0){
			print("Loading call: %s\n", *argv);
			ladd(&tofuzz, &syscalls[index]); // Might be dangerous, pls fix
		}else{
			print("Error: Invalid system call: %s\n", *argv);
			exits("Encountered invalid syscall");
		}
	}
	
	logfd = open("./fuzz.log", OWRITE);
	
	// Operate for the desired number of rounds, -1 is infinite
	for(i = 0; i < nrounds || nrounds < 0; i++){
		int j;
		for(j = 0; j < tofuzz.size; j++){
			// <Log here>
			fuzz((caller*)lget(&tofuzz, j)); // Fuzz (this syncs the disk)
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
	for(i = 0; i < NCALLS; i++)
		if(strcmp(syscalls[i].name, name) == 0)
			return i;
	return -1;
}
