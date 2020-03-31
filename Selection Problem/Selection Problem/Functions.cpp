#include "Functions.h"


void GetPersonsFromUser(int& n, int& k, Person* Array)
{//The function getting inputs from user and creating Person Array
	int id;
	char name[MAX_LEN];
	for (int i = 0; i < n; i++)
	{
		cout << "Please Type the ID and Name of Person number " << i + 1 << ":" << endl;
		cin >> id;
		cin.ignore();
		cin.getline(name, MAX_LEN);
		if (PersonAlreadyExist(Array, i, id))
		{
			cout << "input invalid\n";
			exit(1);
		}
		Array[i] = Person(name, id);
	}
	cout << "Insert the X size in the array you would like to find" << endl;
	cin >> k;
	if (k <= 0 || k > n) // K is'nt in range
	{
		cout << "input invalid\n";
		exit(1);
	}
}
//-----------------------------------------------------------------------//
bool PersonAlreadyExist(Person* arr, int size, int id)
{
	for (int i = 0; i < size; i++)
		if (arr[i].getId() == id)
			return true;
	//else
	return false;
}
//-----------------------------------------------------------------------//
const Person& RandSelection(Person Arr[], int k, int& NumComp)
{	/*Efficiency:
	In the Worst case- Teta(n^2)
	In the Average case - Teta(n)*/
	int right = Person::SizeOfPersons - 1;
	int left = 0;
	return(Selection(Arr, left, right, k, NumComp));
}
//-----------------------------------------------------------------------//
const Person selectHeap(Person* A, int k, int& NumComp)
{	/*Efficiency:
	In the Worst Case: Teta(n logn), K==n*/
	Heap personList(A, Person::SizeOfPersons);//build heap --Teta(n)
	Person Answer;
	for (int i = 0; i < k && !personList.isEmpty(); i++)//if (k==n) this is the worst
		Answer = personList.DeleteMin();//running on heap untill arrving to the k var
		//Worst- Teta(log n)
	NumComp = personList.getNumComp();
	return (Answer);
}
//-----------------------------------------------------------------------//
const Person BST(Person* A, int k, int& NumComp)
{
	/*Efficiency:
	Worst -Teta (n^2), Average - Teta (n logn)*/

	BSTree tree;
	BSTreeNode* res = nullptr;
	for (int i = 0; i < Person::SizeOfPersons; i++) //(n) times
		tree.Insert(A[i], A[i].getId()); //Worst- Teta (n), Average -Teta (log n)

	tree.PrintKValue(tree.getRoot(), k, &res); //Worst- Teta(n), Average- Teta(logn)
	NumComp = BSTree::numComp; //Teta(1)
	return res->getData();
}
//-----------------------------------------------------------------------//
