/*
 * exceptionHandlerTester.h.h
 *
 *  Created on: Nov 21, 2014
 *      Author: ufo008ahw
 */

#ifndef EXCEPTION_HANDLER_TESTER_H
#define EXCEPTION_HANDLER_TESTER_H

#include <iostream>
#include <exception>
#include "rawTester.h"
using namespace std;

/*
 * Learning Tips:
 *
 * 1. try{}, catch() to catch exception in control flow.
 * 2. set_terminate() to set a terminate function in last step call.
 * 3. std::exception usage.
 */


void on_terminate()
{
	std::cout << "terminate() function called!" << std::endl;
}

class exceptionHandlerTester: public rawTester
{
	public:
		void try_catch();
		void set_terminate();
		void doTest();

};

void exceptionHandlerTester::try_catch()
{
	try
	{
		exception oneE;
		throw oneE;
	}
	catch(exception &e)
	{
		cout << e.what() << endl;
	}
	catch(...)
	{
		cout << "other exception" << endl;
	}

	try
	{
		int val = 10;
		throw val;
	}
	catch(int &val)
	{
		cout << "exception " << val << endl;
	}
}

void exceptionHandlerTester::set_terminate()
{
	std::set_terminate(on_terminate);
	throw std::exception();
	std::cout << "terminate() function NOT called!" << std::endl;
}

void exceptionHandlerTester::doTest()
{
	cout << endl;
	cout << "----------- Exception Handler test -----------" << endl;
	this->try_catch();
	this->set_terminate();
}


#endif
