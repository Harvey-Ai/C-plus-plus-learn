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
 * 2. If class has virtual inherite, class will contain a virtual class table pointer.
 * 3. virtual inherite only search its father to cut the same data, see derivedClass5 and derivedClass6;
 * 4. virtual function table can be inherited, but virtual inhertaince can't because of father-son relationship. So one class has only one virtual function table, but may be many virtual inheritance table.
 * 5. function don't cost memory.
 * 6. In my system, the virtual inherite and virtual function ptr implemented by one table.
 */

class baseClass
{
	public:
		int a;
		char b;
//		void fun(){}
};

// common inherite
class derivedClass : public baseClass
{
	public:
		int a;
};

// with virtual function
class derivedClass2 : public baseClass
{
	public:
		int a;
		virtual void fun(){}
};

// virtual inherite
class derivedClass3 : virtual public baseClass
{
	int a;
};


// common inherite a class with virtual ptr, with virtual inherite class
class derivedClass4 : virtual public derivedClass3
{
	int a;
};


// common inherite a class with virtual ptr, with virtual function
class derivedClass5 : public derivedClass3
{
	public:
		int a;
		virtual void fun(){}
};


// virtual inherite two common class, do not work
class derivedClass6 : public derivedClass2, derivedClass
{
};


// virtual inherite two common class, do not work
class derivedClass7 : public virtual derivedClass2, virtual derivedClass
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
	cout << "class baseClass { int a; char b; };" << endl;
	cout << "baseClass storage: |char|int|, after do alignment size = " << sizeof(baseClass) << endl;
	cout << endl;

	cout << "class derivedClass : public baseClass { int a };" << endl;
	cout << "derivedClass storage: |char|int|int|, size = " << sizeof(derivedClass) << endl;
	cout << endl;

	cout << "class derivedClass2 : public baseClass { "
			" int a; "
			" virtual void fun(){} "
			" };" << endl;
	cout << "derivedClass2 storage: {baseClass}|int|Vtableptr|, size = " << sizeof(derivedClass2) << endl;
	cout << endl;

	cout << "class derivedClass3 : virtual public baseClass{ int a; }" << endl;
	cout << "derivedClass3 storage: {baseClass}|int|Vclassptr|, size = " << sizeof(derivedClass3) << endl;
	cout << endl;

	cout << "classs derivedClass4 : virtual public derivedClass3{ int a; }" << endl;
	cout << "derivedClass4 storage: {derivedClass3}|int|Vclassptr|, size = " << sizeof(derivedClass4) << endl;
	cout << endl;

	cout << "classs derivedClass5 : public derivedClass3 {"
			" int a; "
			" virtual void fun(){} "
			" };" << endl;
	cout << "derivedClass5 storage: {derivedClass3}|int|Vtableptr(share with derivedClass3)|, size = " << sizeof(derivedClass5) << endl;
	cout << "!think about why the sizeof(derivedClass5) = " << sizeof(derivedClass5) << endl;
	cout << endl;

	cout << "classs derivedClass6 : public derivedClass2, derivedClass{}" << endl;
	cout << "derivedClass6 storage: |{derivedClass}|{derivedClass2}|, size = " << sizeof(derivedClass6) << endl;
	cout << endl;

	cout << "classs derivedClass7 : virtual public derivedClass2, derivedClass{}" << endl;
	cout << "derivedClass7 storage: |{derivedClass}|{derivedClass2}|Vclassptr|, size = " << sizeof(derivedClass7) << endl;
	cout << endl;

}

#endif /* CLASSSTORAGE_H_ */
