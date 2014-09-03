/*
 * unInheritedClass.h
 *
 *  Created on: Aug 26, 2014
 *      Author: ufo008ahw
 */

#ifndef UNINHERITEDCLASS_H_
#define UNINHERITEDCLASS_H_

#include <iostream>
#include "rawClass.h"
using namespace std;


/* Learning tips: Virtual inherit, in C++, it is a technique for solving
 * the diamond inherit in multi-inherit. By the way, virtual inherited class's
 * construction have more priority than ordinal.
 *
 * 1. In virtual inherit class, the most bottom derived class need do the
 * construction by its self.
 * 2. Place the construction function in private can forbit somethings. In this
 * example shows a un-inherited class.
 */

class classA
{
	friend class classB;
	private:
		classA();
	public:
};

// ClassB is un-inherited
class classB: virtual public classA
{
	public:
		classB() : classA()
		{}
};


// remove comment to learn.
/*
class classC: public classB
{
	public:
		classC() : classB()
		{}

};
*/

class unInheritedClass: public rawClass
{
	public:
		void doTest();
};


void unInheritedClass::doTest()
{
	cout << endl;
	cout << "----------- Un-inherited class -----------" << endl;
	cout << "classC is un-inheritable, YES" << endl;
}


#endif /* UNINHERITEDCLASS_H_ */
