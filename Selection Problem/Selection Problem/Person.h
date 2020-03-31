#ifndef _Person_H
#define _Person_H

#include <string.h>
#include <iostream>
using namespace std;
#pragma warning(disable : 4996)

class Person
{
private://Private var
	int id;
	char* name;

public:
	static int SizeOfPersons;

public:
	// Public Methods
	Person();
	Person(const char* name, const int id);//ctor
	Person(const Person& other);
	Person(Person&& other);
	~Person();//d'tor

	//Operators
	const Person& operator=(const Person& other);
	const Person& operator=(Person&& other);
	bool operator>(const Person& other) const;
	bool operator<(const Person& other) const;
	bool operator==(const Person& other) const;
	//gets
	const int getId() const;
	const char* getName() const;
	//sets
	void setName(const char* name);
	void setId(const int id);

	friend void swapPerson(Person& pOne, Person& pTwo)
	{
		Person temp = pOne;
		pOne = move(pTwo);
		pTwo = move(temp);
	}

};

#endif  // !_Person_H