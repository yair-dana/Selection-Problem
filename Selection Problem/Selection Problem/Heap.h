#ifndef _HEAP_H_
#define _HEAP_H_
#include "Person.h"

class Heap
{

private://Private vat
	Person* data;
	int maxSize;
	int heapSize;
	int NumComp;
	int allocated;

private://Private Methods
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);

public://Public Methods
	Heap(int max);
	Heap(Person Array[], int n);
	~Heap();

	Person& Min();
	Person DeleteMin();
	int getNumComp();
	void Insert(Person& item);
	bool isEmpty();
	void makeEmpty();

};
#endif // !_HEAP_H_
