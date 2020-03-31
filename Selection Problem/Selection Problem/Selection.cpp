#include "Selection.h"

//-----------------------------------------------------------------------//
const Person& Selection(Person* Arr, int left, int right, int i, int& NumComp)
{
	//In the Worst case- Teta(n^2)
	//in the Average case - Teta(n)
	int pivot, leftPart, idx;
	srand((unsigned)time(NULL));
	idx = left + rand() % (right - left + 1);
	swapPerson(Arr[idx], Arr[left]);

	pivot = Partition(Arr, left, right, NumComp);
	leftPart = pivot - left + 1;
	if (i == leftPart)
		return Arr[pivot];
	if (i < leftPart)
		return Selection(Arr, left, pivot - 1, i, NumComp);
	else
		return Selection(Arr, pivot + 1, right, i - leftPart, NumComp);
}
//-----------------------------------------------------------------------//
static int Partition(Person* Arr, int left, int right, int& NumComp)
{
	int pivot = Arr[left].getId();

	while (left != right)
	{
		NumComp++;
		if (Arr[left] > Arr[right])
			swapPerson(Arr[left], Arr[right]);
		if (pivot == Arr[left].getId())
			right--;
		else //pivot==Arr[right]
			left++;
	}
	return left;
}
//-----------------------------------------------------------------------//

