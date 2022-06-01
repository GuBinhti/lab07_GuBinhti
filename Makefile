all: runtests

default: runtests

runtests: heap.o examheap.o
	g++ -std=c++11 -g heap.o examheap.o -o runtests

clean:
	/bim/rm -f runtests *.o