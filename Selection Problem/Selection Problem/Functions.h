#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "Person.h"
#include "BSTree.h"
#include "BSTreeNode.h"
#include "Heap.h"
#include "Selection.h"
#include <iostream>
using namespace std;
#define MAX_LEN 20


void GetPersonsFromUser(int& n, int& k, Person* Array);
const Person& RandSelection(Person Arr[], int k, int& NumComp);
const Person selectHeap(Person* A, int k, int& NumComp);
const Person BST(Person* A, int k, int& NumComp);
bool PersonAlreadyExist(Person* arr, int size, int id);
#endif // Function_H
