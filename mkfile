</$objtype/mkfile

TARG = fuzz

BIN = /$objtype/bin

OFILES = main.$O \
		input.$O \
		mutate.$O \
		list.$O \
		inlist.$O

HFILES = fuzz.h list.h mutate.h

MAN = /sys/man/1

</sys/src/cmd/mkone

# Add things after this line

debug: nuke
	 mk all 'CFLAGS=$CFLAGS -DDEBUG'
