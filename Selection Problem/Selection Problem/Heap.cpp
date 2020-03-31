#include "Heap.h"
#include <iostream>

Heap::Heap(int max)
{
	data = new Person[max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
	NumComp = 0;
}
//-----------------------------------------------------------------------//
Heap::Heap(Person Array[], int n)
{
	//BUILD HEAP FUNCTION
	heapSize = maxSize = n;
	NumComp = 0;
	data = Array;
	allocated = 0;

	for (int i = (n / 2) - 1; i >= 0; i--)
		FixHeap(i);
}
//-----------------------------------------------------------------------//
Heap::~Heap()
{
	if (allocated)
		delete data;
	data = nullptr;
}
//-----------------------------------------------------------------------//
int Heap::Left(int node)
{
	return (2 * node + 1);
}
//-----------------------------------------------------------------------//
int Heap::Right(int node)
{
	return (2 * node + 2);
}
//-----------------------------------------------------------------------//
int Heap::Parent(int node)
{
	return (node - 1) / 2;
}
//-----------------------------------------------------------------------//
void Heap::FixHeap(int node)
{	//Worst case O(log n)
	int min;
	int left = Left(node);
	int right = Right(node);

	if ((left < heapSize) && (data[left] < data[node]))
		min = left;
	else min = node;
	if ((right < heapSize) && (data[right] < data[min]))
		min = right;

	NumComp += 2;
	if (min != node)
	{
		swapPerson(data[node], data[min]);
		FixHeap(min);
	}
}
//-----------------------------------------------------------------------//
Person& Heap::Min()
{
	return (data[0]);
}
//-----------------------------------------------------------------------//
Person Heap::DeleteMin()
{
	if (heapSize < 1)
	{
		std::cout << "Error: EMPTY HEAP\n";
		exit(1);
	}
	Person Min = data[0];
	heapSize--;
	data[0] = data[heapSize];
	FixHeap(0);
	return Min;
}
//-----------------------------------------------------------------------//
int Heap::getNumComp()
{
	return NumComp;
}
//-----------------------------------------------------------------------//
void Heap::Insert(Person& item)
{
	if (heapSize == maxSize)
	{
		cout << "Error: HEAP FULL\n";
		exit(1);
	}
	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)] > item))
	{
		NumComp++;
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	NumComp += 1;
	data[i] = item;
}
//-----------------------------------------------------------------------//
bool Heap::isEmpty()
{
	if (heapSize == 0)
		return true;
	return false;
}
//-----------------------------------------------------------------------//
void Heap::makeEmpty()
{
	while (!isEmpty())
		DeleteMin();
}
//-----------------------------------------------------------------------//

	