#include "Functions.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


int main()
{
	/*runs on three algorithims of Data Sctures - Selection,Heap,BST
	runs on a list of persons and returns the person with the id in the 'x' size
	while getting that person from those three diffrent algorithims
	 also printing how many compares did each algorithm do on his run */
	int n, k;
	int numCompSelection = 0, numCompHeap = 0, numCompBST = 0;
	Person resSelection, resSelectHeap, resBST;
	Person* Person_Array, * BSTarr, * HeapArr;

	cout << "Please Type The numbers of the PERSONS?";
	cin >> n;
	if (n <= 0)
	{
		cout << "input invalid\n";
		exit(1);
	}
	Person_Array = new Person[n];
	BSTarr = new Person[n];
	HeapArr = new Person[n];
	GetPersonsFromUser(n, k, Person_Array);

	for (int i = 0; i < n; i++)//copy to other tests arrays 
	{
		BSTarr[i] = Person_Array[i];
		HeapArr[i] = Person_Array[i];
	}
	//Random Function
	resSelection = RandSelection(Person_Array, k, numCompSelection);
	//selectHeap
	resSelectHeap = selectHeap(HeapArr, k, numCompHeap);
	//BST
	resBST = BST(BSTarr, k, numCompBST);

	if (resBST == resSelectHeap && resBST == resSelection)
	{//The same Person in the Array
		cout << resSelection.getId() << " " << resSelection.getName() << "\n\n";
		cout << "RandSelection: " << numCompSelection << " comparisons" << endl << endl;
		cout << "selectHeap: " << numCompHeap << " comparisons" << endl << endl;
		cout << "BST: " << numCompBST << " comparisons" << endl << endl;
	}

	delete[]BSTarr;
	delete[]HeapArr;
	delete[]Person_Array;

}
