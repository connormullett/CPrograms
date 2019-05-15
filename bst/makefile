
a.out: main.o bst.o
	gcc main.o bst.o 

main.o: main.c
	gcc -c main.c

bst.o: bst.c bst.h
	gcc -c bst.c

clean:
	rm *.o 
	rm *.s
	rm *.out

