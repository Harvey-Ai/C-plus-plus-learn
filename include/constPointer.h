/*
 * constPointer.h
 *
 *  Created on: Aug 20, 2014
 *      Author: ufo008ahw
 */

#ifndef CONSTPOINTER_H_
#define CONSTPOINTER_H_

/* learning tips
 * 1. const point: decoreate type use const.
 * 2. point to const: decoreate var use const.
 */

class constPointer: public rawClass
{
private:
	// regular pointer point const variable
	const int *constIntPtr;
	int const *intConstPtr;
	// const pointer
	int* const intPtrConst = new(int);
public:

	void doTest();
};

void constPointer::doTest()
{
	constIntPtr = new int;
	// *constIntPtr = 1;
	intConstPtr = (const int*)::operator new(4);

	// intPtrConst = new(int);
	*intPtrConst = 10;

	// cout << "intPtrConst->" << *intPtrConst << endl;
}


#endif /* CONSTPOINTER_H_ */
