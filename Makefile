all: examheap

default: examheap

examheap: heap.cpp examheap.cpp
	g++ -std=c++11 -g heap.cpp examheap.cpp -o examheap

clean:
	/bim/rm -f examheap *.o