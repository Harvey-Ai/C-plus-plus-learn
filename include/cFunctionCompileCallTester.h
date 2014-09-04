/*
 * cFunctionCompileCall.h
 *
 *  Created on: Aug 25, 2014
 *      Author: ufo008ahw
 */

#ifndef CFUNCTIONCOMPILECALL_H_
#define CFUNCTIONCOMPILECALL_H_

#include <iostream>
#include "rawTester.h"
using namespace std;


/* Learning tips: Unlike C++, C compiler don't consider parameters in compiled code,
 * so it need carefully consideration in call different C module, and C++ need active show
 * their calling C module code.
 *
 * 1. Call C module function by C++: extern "C".
 * 2. Call C module function with different parameters: it is better
 * to cite declaration in C, or a different declaration will make result unpredictable.
 * 3. Coder can use nm check the symbol information.
 */

extern "C"
{
	// different declaration from cFunctionCompileDefine.h
	int cSum(int a);
}

class cFunctionCallTester : public rawTester
{
	public:
		void doTest();
};

void cFunctionCallTester::doTest()
{
	cout << endl;
	cout << "----------- unmatch funcion caller test -----------" << endl;
	cout << "a = 1000, use fun(a) call fun(a, b), the result is unpredictable: " << endl;
	cout << "a + b = "<< cSum(1000) << endl;
}

#endif /* CFUNCTIONCOMPILECALL_H_ */
