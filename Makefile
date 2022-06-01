all: examheap

default: examheap

examheap: heap.o examheap.o
	g++ -std=c++11 -g heap.o examheap.o -o examheap

clean:
	/bim/rm -f examheap *.o