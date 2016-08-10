bbfs: bbfs.o log.o dictionary.o arreglo.o
	gcc -g -o bbfs bbfs.o log.o dictionary.o arreglo.o `pkg-config fuse --libs`

bbfs.o: bbfs.c log.h params.h
	gcc -g -Wall `pkg-config fuse --cflags` -c bbfs.c

log.o: log.c log.h params.h
	gcc -g -Wall `pkg-config fuse --cflags` -c log.c

dictionary.o: dictionary.c dictionary.h arreglo.h
	gcc -g -Wall -c dictionary.c

arreglo.o: arreglo.c arreglo.h
	gcc -g -Wall -c arreglo.c

dict-test: dict-test.o log.o dictionary.o arreglo.o
	gcc -g -o dict-test dict-test.o log.o dictionary.o arreglo.o `pkg-config fuse --libs`

dict-test.o: dict-test.c dictionary.h
	gcc -g -Wall -c dict-test.c

clean:
	rm -f *.o bbfs dict-test
