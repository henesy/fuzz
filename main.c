#include <u.h>
#include <libc.h>
#include "fuzz.h"

void
usage(void)
{
	fprint(2, "usage: %s [-k kernel name]\n", argv0);
	exits("usage");
}

void
main(int argc, char *argv[])
{
	char *kname;

	ARGBEGIN{
		case 'k':
			kname = ARGF();
			break;
		default:
			usage();
	}ARGEND

	

	exits(nil);
}
