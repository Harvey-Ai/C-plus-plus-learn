#include <iostream>
#include <climits>
#include "rawTester.h"
using namespace std;


/* Learning tips
 *
 * 1. Be careful of the type conversion in C. in the "? :" operation, the result type is
 * depend on both last two operands.
 * 2. View the typedef as a variable declaration.
 * 3. The #if condition compilation is calculated in the pre_process part, so ordinary variable
 * can't work in the #if, even the sizeof operator.
 *
 */

/* learning tips
 * 1. const point: decoreate type use const.
 * 2. point to const: decoreate var use const.
 */


class basicGramTester: public rawTester
{
	private:

	public:
		typedef int intType;
		void doTest();
};

void basicGramTester::doTest()
{
	cout << endl;
	cout << "----------- basic grammer test -----------" << endl;
	cout << "sizeof(1 > 0 ? 1 : 0) = " << sizeof(1 > 0 ? 1 : 0) << ", " \
			<< (sizeof(1 > 0 ? 1 : 0) == sizeof(int) ? "YES" : "NO") << endl;
	cout << "sizeof(1 > 0 ? 1 : 0.0) = " << sizeof(1 > 0 ? 1 : 0.0) << ", " \
			<< (sizeof(1 > 0 ? 1 : 0.0) == sizeof(double) ? "YES" : "NO") << endl;

	basicGramTester::intType intValue;
	cout << "basicGramTester::intType intValue, sizeof(intValue) = " << sizeof(intValue) << ", " \
			<< (sizeof(int) == sizeof(intValue) ? "YES" : "NO") << endl;

	int macroCond = 1;
#if macroCond
	cout << "macroCond work, NO" << endl;
#else
	cout << "macroCond do not work. YES" << endl;
#endif

#define definedMarcoCond 1
#if definedMarcoCond
	cout << "definedMarcoCond work, YES" << endl;
#else
	cout << "definedMarcoCond do not work. NO" << endl;
#endif

/*
	// regular pointer point const variable
	const int *constIntPtr;
	int const *intConstPtr;
	// const pointer
	int* const intPtrConst = new(int);

	constIntPtr = new int;
		// *constIntPtr = 1;
		intConstPtr = (const int*)::operator new(4);

		// intPtrConst = new(int);
		*intPtrConst = 10;

		// cout << "intPtrConst->" << *intPtrConst << endl;
*/


	cout << "int max: " << INT_MAX << endl;
}
