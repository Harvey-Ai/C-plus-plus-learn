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

/* Learning tips
 *
 * 1. New operator: for allocate memory and construct obj.
 * 2. Operator new: only for allocate memory.
 * 3. Placement new: construct obj in specified memory.
 * 4. Operator new and delete is always static.
 */

class operatorNew: public rawClass
{
private:
	static list<operatorNew *> memList;

public:
	static void* operator new(size_t size, operatorNew* ptr = NULL);
	static void operator delete(void *p, size_t size);
	void doTest();
};
list<operatorNew *> operatorNew::memList;


void* operatorNew::operator new(size_t size, operatorNew* ptr)
{
	static int cnt = 0;
	// get memory by malloc or new
	if (ptr == NULL)
	{
		operatorNew *p = NULL;
		if (cnt % 2)
		{
			p = (operatorNew *)malloc(size);
			cout << "use malloc set memory, " << p <<endl;
		}
		else
		{
			p = (operatorNew *)::operator new(size);
			cout << "use operator new set memory, " << p << endl;
		}
		memList.push_back(p);
		return p;
	}
	else
	{
		cout << "use exsit memory, palcement new" << endl;
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
			cout << "free " << p << " by free" << endl;
			free(*it);
			break;
		}
	}
}

void operatorNew::doTest()
{
	cout << endl;
	cout << "----------- operator new test -----------" << endl;
	operatorNew *p = new operatorNew();
	cout << "adress p: " << p << endl;
	operatorNew *p2 = new(p) operatorNew;
	cout << "after palcement new, p2 == p ? " << (p == p2 ? "YES" : "NO") << endl;

	assert(memList.size() == 2);
	delete p;
}

#endif
