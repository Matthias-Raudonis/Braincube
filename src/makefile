CC=gcc
CFLAGS= -c -I.
all:main

main: main.o functions.o
     $(CC) -o main functions.o main.o

main.o: main.c functions.h config.h
		 $(CC) $(CFLAGS) main.c 

functions.o: functions.c functions.h config.h
		 $(CC) $(CFLAGS) functions.c
