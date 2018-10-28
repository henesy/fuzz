#include <u.h>
#include <libc.h>
#include "fuzz.h"

void
usage(void)
{
	fprint(2, "usage: %s [-n rounds] calls\n", argv0);
	exits("usage");
}

void
main(int argc, char *argv[])
{
	int nrounds = -1;
	int i;
	List syscalls;

	ARGBEGIN{
		case 'n':
			// Number of rounds to iterate fuzzing for
			nrounds = atoi(ARGF());
			break;
		default:
			usage();
	}ARGEND

	// Acquire a list of calls specified by spaces (fuzz -n 1 read write seek)
	for(;*argv;){
		print("Loading call: %s\n", *argv++);
		// TODO -- add to list
	}
	
	// Operate for the desired number of rounds, -1 is infinite
	for(i = 0; i < nrounds || nrounds < 0; i++){
		
	}

	exits(nil);
}
