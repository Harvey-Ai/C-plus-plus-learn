/*
 * classStorage.h
 *
 *  Created on: Aug 26, 2014
 *      Author: ufo008ahw
 */

#ifndef CLASSSTORAGE_H_
#define CLASSSTORAGE_H_

#include <iostream>
#include "rawTester.h"
using namespace std;

/* Learning tips: Virtual function and virtual inherit is RTTI(Run-Time Type Identification)
 * techniques in C++. And it cost more storage to do this, virtual table.
 *
 * 1. If class has virtual function, class will contain a virtual table
 * pointer, the virtual table don't occupy the class's storage.
 * 2. If class has virtual inherite, class will contain a virtual class table
 * pointer.
 */

class baseClass
{
	private:
		char b;
};

class derivedClass : public baseClass
{
	private:
		int c;
};

class derivedClass2 : public baseClass
{
	public:
		virtual void function(){}
};

class derivedClass3 : virtual public baseClass
{
};

class derivedClass4 : public derivedClass3
{
};

////////////////////////

class classStorageTester : public rawTester
{
	public:
		void doTest();
};

void classStorageTester::doTest()
{
	cout << endl;
	cout << "----------- Class storage test -----------" << endl;
	cout << "class baseClass { char b; };" << endl;
	cout << "baseClass storage: |char|, after do alignment size = " << sizeof(baseClass) << endl;
	cout << endl;

	cout << "class derivedClass : public baseClass { int c };" << endl;
	cout << "derivedClass storage: |int|baseClass|, size = " << sizeof(derivedClass) << endl;
	cout << endl;

	cout << "class derivedClass2 : public baseClass {"
			"virtual void function(){}"
			"};" << endl;
	cout << "derivedClass2 storage: |baseClass|Vtableptr|, size = " << sizeof(derivedClass2) << endl;
	cout << endl;

	cout << "class derivedClass3 : virtual public baseClass{}" << endl;
	cout << "derivedClass3 storage: |baseClass|Vclassptr|, size = " << sizeof(derivedClass3) << endl;
	cout << endl;

	cout << "classs derivedClass4 : public derivedClass3{}" << endl;
	cout << "derivedClass4 storage: |derivedClass3|, size = " << sizeof(derivedClass4) << endl;
	cout << endl;
}

#endif /* CLASSSTORAGE_H_ */
