
CC=gcc
CFLAGS=-Wall 
OPT=-O
OUTPUT=result.txt

all: debbug

debbug:	main.c
	cp ../zad01/libstatic.a .
	$(CC) -g $(CFLAGS) $(OPT) $^ -L. -lstatic -o $@.out
	./$@.out

clean:
	rm -f *.out  *.so *.a *.[0-9]* 
	rm -rf *.out.dSYM
