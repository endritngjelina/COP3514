#Endrit Ngjelina COP 436 303 72
#this file is a makefile for project 10 and the other files

#compiler and flags
CC = gcc
CFLAGS = -Wall -std=c11

all: project10_guests

#linking rule for project10_guests executable
project10_guests: guest.o read_line.o project10_guests.o
	$(CC) $(CFLAGS) -o $@ $^

#compilation rule for guest.o
guest.o: guest.c guest.h read_line.h
	$(CC) $(CFLAGS) -c $<

#compilation rule for read_line.o
read_line.o: read_line.c read_line.h
	$(CC) $(CFLAGS) -c $<

#compilation rule for project10_guests.o
project10_guests.o: project10_guests.c guest.h read_line.h
	$(CC) $(CFLAGS) -c $<

#clean rule for removing object files and the executable
clean:
	rm -f *.o project10_guests