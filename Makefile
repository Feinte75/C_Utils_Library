CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -pedantic -g
SRCS= linked_list.c example_linked_list.c

OBJS= $(SRCS:.c=.o)

default : example
	
example : $(OBJS)
	$(CC) $^ -o $@
	
%.o : %.c
	$(CC) $< $(CFLAGS) -c -o $@

clean : 
	rm *.o