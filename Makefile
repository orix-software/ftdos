CC=cl65
CFLAGS=-ttelestrat
LDFILES=
PROGRAM=ftdos
LDFILES=

ifeq ($(CC65_HOME),)
        CC = cl65
        AS = ca65
        LD = ld65
        AR = ar65
else
        CC = $(CC65_HOME)/bin/cl65
        AS = $(CC65_HOME)/bin/ca65
        LD = $(CC65_HOME)/bin/ld65
        AR = $(CC65_HOME)/bin/ar65
endif


all : code
.PHONY : all



SOURCE=src/main.c

VERSION=$(shell cat VERSION)

  
code: $(SOURCE)
	mkdir build/bin -p
	mkdir build/usr/share/ftdos/ -p
	$(CC) -ttelestrat src/main.c src/exec.s  -o build/bin/$(PROGRAM)
	./docs/builddocs.sh
	mkdir build/HOME/BASIC11/DSK -p
	cp runtime/LOAD-FTD.TAP build/HOME/BASIC11/
	cp runtime/FTDOS.DSK build/HOME/BASIC11/dsk
	cp runtime/FTDOS376.SYS build/


