
#ifndef _SELECTION_H_
#define _SELECTION_H_

#include "Person.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

const Person& Selection(Person* Arr, int left, int right, int i, int& NumComp);
static int Partition(Person* Arr, int left, int right, int& NumComp);


#endif // !_SELECTION_H_