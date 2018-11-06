</$objtype/mkfile

TARG = fuzz

BIN = /$objtype/bin

OFILES = main.$O \
		input.$O \
		mutate.$O \
		list.$O 

HFILES = fuzz.h list.h

MAN = fuzz.man

</sys/src/cmd/mkone
