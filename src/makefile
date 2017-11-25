CC=gcc
CFLAGS=-I.
all:main

main: main.o
     $(CC) -o functions.o main.o

main.o: main.c functions.h config.h
		 $(CC) $(CFLAGS) main.c functions.h config.h

functions.o: functions.c functions.h config.h
		 $(CC) $(CFLAGS) functions.c functions.h config.h
