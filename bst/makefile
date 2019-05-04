
output: main.o bst.o
	gcc main.o bst.o -o output	

main.o: main.c
	gcc -c main.c

bst.o: bst.c bst.h
	gcc -c bst.c

clean:
	rm *.o 
	rm output

