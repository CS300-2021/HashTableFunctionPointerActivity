CC=gcc
CFLAGS=-Wall -g

.PHONY: all clean

all: bin bin/driver 

bin:
	mkdir -p bin
	
bin/driver: bin/driver.o bin/ht.o
	${CC} ${CFLAGS} bin/driver.o bin/ht.o -o bin/driver
	
bin/driver.o: src/driver.c 
	${CC} ${CFLAGS} -c src/driver.c -o bin/driver.o
	
bin/ht.o: src/ht.c include/ht.h
	${CC} ${CFLAGS} -c src/ht.c -o bin/ht.o
	
clean:
	rm -rf bin/*.o bin/driver