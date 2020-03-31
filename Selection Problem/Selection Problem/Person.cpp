#include "Person.h"

//-----------------------------------------------------------------------//
Person::Person()
{
	//cout << "PERSON CTOR\n";
	id = -1;
	name = nullptr;
}
//-----------------------------------------------------------------------//
Person::Person(const char* name, const int id) :id(id)
{
	//cout << "PERSON CTOR\n";
	this->name = strdup(name);
	SizeOfPersons++;
}
//-----------------------------------------------------------------------//
Person::Person(const Person& other)
{
	//cout << "PERSON COPY\n";
	*this = other;
}
//-----------------------------------------------------------------------//
Person::Person(Person&& other)
{
	//cout << "PERSON MOVE\n";
	*this = move(other);
}
//-----------------------------------------------------------------------//
Person::~Person()
{
	delete (name);
}
//-----------------------------------------------------------------------//
const Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		this->id = other.id;
		this->name = strdup(other.name);
	}
	return *this;
}
//-----------------------------------------------------------------------//
const Person& Person::operator=(Person&& other)
{
	if (this != &other)
	{
		this->id = other.id;
		this->name = (other.name);
		other.name = nullptr;
	}
	return *this;
}
//-----------------------------------------------------------------------//
bool Person::operator>(const Person& other) const
{
	if (id > other.getId())
		return true;
	return false;
}
//-----------------------------------------------------------------------//
bool Person::operator<(const Person& other) const
{
	if (id < other.getId())
		return true;
	return false;
}
//-----------------------------------------------------------------------//
bool Person::operator==(const Person& other) const
{
	if (this->id == other.getId() && strcmp(this->name, other.getName()) == 0)
		return true;
	//else
	return false;
}
//-----------------------------------------------------------------------//
const int Person::getId() const
{
	return id;
}
//-----------------------------------------------------------------------//
const char* Person::getName() const
{
	return name;
}
//-----------------------------------------------------------------------//
void Person::setName(const char* name)
{
	this->name = strdup(name);
}
//-----------------------------------------------------------------------//
void Person::setId(const int id)
{
	this->id = id;
}
//-----------------------------------------------------------------------//
int Person::SizeOfPersons = 0;
//-----------------------------------------------------------------------//

