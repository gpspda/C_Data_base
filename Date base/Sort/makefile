

.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g 
BIN=Bubble Double_Bubble Select Insert Quick Shell Merge Heap
 

all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)


