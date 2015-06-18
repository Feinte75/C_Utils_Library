CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -pedantic -g

default : linked_list

linked_list : linked_list.o
	$(CC) $(CFLAGS) -o linked_list linked_list.o

linked_list.o : linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c