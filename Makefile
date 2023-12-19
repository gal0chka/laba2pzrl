.PHONY: all clean run

CC = gcc

all: start

start: main.o solve.o bin.o oct.o hex.o
	$(CC) main.o solve.o bin.o oct.o hex.o -o start -lm

main.o: main.c
	$(CC) -c main.c

solve.o: solve.c
	$(CC) -c solve.c

bin.o: bin.c 
	$(CC) -c bin.c

oct.o: oct.o
	$(CC) -c oct.c

hex.o: hex.c
	$(CC) -c hex.c

run: start
	./start

clean:
	rm -rf *.o start



