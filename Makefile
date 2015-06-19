CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -pedantic -g
SRCS= linked_list.c example.c

OBJS= $(SRCS:.c=.o)

default : example
	
example : $(OBJS)
	$(CC) $^ -o $@
	
%.o : %.c
	$(CC) $< $(CFLAGS) -c -o $@

clean : rm *.o