FLAG= -g -std=gnu11 -Wall

all: main.o
	gcc $(FLAG) main.o -o main

main.o: main.c tournament.c tournament.h players.dat
	gcc $(FLAG) -c main.c -o main.o

run: all
	./main

checkmem: all
	valgrind ./main

clean:
	rm main.o main
