

.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=stack01  stack02
 

all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)


