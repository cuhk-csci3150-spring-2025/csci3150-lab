# You can change this file to try different Makefile rules.
# Makefile require **tab** for indentation.
all: main

main: add_int.o multi_int.o main.o
	gcc add_int.o multi_int.o main.o -o main

add_int.o: add_int.c
	gcc -c add_int.c

multi_int.o: multi_int.c
	gcc -c multi_int.c

main.o: main.c
	gcc -c main.c

clean:
	rm *.o main