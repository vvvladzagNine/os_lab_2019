all: task1 task3


task1:
	make -F ./task1/makefile

task3: process_memory.c
	gcc -o hello_memory process_memory.c

task5: ./task1/utils.c parallel_sum.c libsumm
	gcc -o task5.out parallel_sum.c ./task1/utils.c -std=gnu99 -I./task1 -L./ -lm -lsum -lpthread

task5_no_lib: ./task1/utils.c parallel_sum.c ./libsum/sum.c
	gcc -o parallel_sum.out parallel_sum.c ./task1/utils.c ./libsum/sum.c -std=gnu99 -I./task1 -I./libsum -L./ -lm -lpthread

libsumm: ./libsum/sum.c
	gcc -o ./libsum/sum.o -c ./libsum/sum.c -I./libsum/
	ar rcs ./libsum.a ./libsum/sum.o
	rm ./libsum/sum.o

clean:
	rm -rf *.out *.o -f *.a
