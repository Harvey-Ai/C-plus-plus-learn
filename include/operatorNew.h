#ifndef OPERATORNEW_H_
#define OPERATORNEW_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <cassert>
#include <new>
#include "rawClass.h"
using namespace std;

/* learning tips
 * 1. new operator: for allocate memory and construct obj
 * 2. operator new: only for allocate memory.
 * 3. placement new: construct obj in specified memory.
 */
class operatorNew: public rawClass
{
private:
	int value;
	static list<operatorNew *> memList;

public:
	operatorNew();
	~operatorNew();
	static void* operator new(size_t size, operatorNew* ptr = NULL);
	static void operator delete(void *p, size_t size);
	void doTest();
};
list<operatorNew *> operatorNew::memList;

operatorNew::operatorNew()
{
	value = 0;
}

operatorNew::~operatorNew()
{
}

void operatorNew::doTest()
{
	operatorNew *p = new operatorNew();
	p->value = 100;
	cout << "Get a new obj.value=" << p->value << endl;

	operatorNew *p2 = new(p) operatorNew;
	p2->value = 1;
	cout << "after palcement new, obj.value=" << p->value << endl;

	assert(memList.size() == 2);
	delete p;
}

void* operatorNew::operator new(size_t size, operatorNew* ptr)
{
	// get memory by malloc or new
	if (ptr == NULL)
	{
		cout << "do operator new" << endl;
		operatorNew *p = (operatorNew *)malloc(size);
		// cout << "get " << size << " size by new" << endl;
		// operatorNew *p = ::operator new(size);
		memList.push_back(p);
		return p;
	}
	else
	{
		cout << "do a palcement new" << endl;
		return ptr;
	}
}

void operatorNew::operator delete(void *p, size_t size)
{
	list<operatorNew *>::iterator it;
	for(it = memList.begin();it != memList.end();it++)
	{
		if (p == *it)
		{
			cout << "free value" << (*it)->value << endl;
			free(*it);

			// cout << "delete value" << (*it)->value << endl;
			// ::operator delete (*it);
			break;
		}
	}
}

#endif
