#include <iostream>
#include <climits>
#include "rawTester.h"
using namespace std;


/* Learning tips : See below
 */

class explicitTester
{
	private:
		int value;
	public:
		explicitTester(){ value = 10; }
		explicitTester(int v) { value = v;}
		explicit explicitTester(int *v) { value = *v;}
};


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
	// 1. Be careful of the type conversion in C. in the "? :" operation, the result type is
	// depend on both last two operands.
	cout << "sizeof(1 > 0 ? 1 : 0) = " << sizeof(1 > 0 ? 1 : 0) << ", " \
			<< (sizeof(1 > 0 ? 1 : 0) == sizeof(int) ? "YES" : "NO") << endl;
	cout << "sizeof(1 > 0 ? 1 : 0.0) = " << sizeof(1 > 0 ? 1 : 0.0) << ", " \
			<< (sizeof(1 > 0 ? 1 : 0.0) == sizeof(double) ? "YES" : "NO") << endl;

	// 2. View the typedef as a variable declaration.
	basicGramTester::intType intValue;
	cout << "basicGramTester::intType intValue, sizeof(intValue) = " << sizeof(intValue) << ", " \
			<< (sizeof(int) == sizeof(intValue) ? "YES" : "NO") << endl;

	// 3. The #if condition compilation is calculated in the pre_process part, so ordinary variable
	// can't work in the #if, even the sizeof operator.
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



	// 4. Const qualifier
	// 1) Const decoreate class type
	const int *constIntPtr = (const int*)new int(1);
	int const *constIntPtr2 = (const int*)new int(1);
	// 2) Const decoreate pointer
	int* const constPtr = new int(1);

	cout << "Before, const int ptr = " << *constIntPtr << ", ";
	cout << "after, assignment ptr = " << (constIntPtr = (const int*)new int(2), *constIntPtr) << endl;
	cout << "Before const int ptr2 = " << *constIntPtr2 << ", ";
	cout << "after, assignment ptr2 = " << (constIntPtr2 = (const int*)new int(2), *constIntPtr2) << endl;

	// 5. Explicit: prevent implicit conversion by the copy Constructor with one parameter.
	explicitTester oneExplicitTester;
	oneExplicitTester = 10;
	int a = 10;
	// Forbit Constructor to do "convert int pointer to explicitTesterClass".
	// oneExplicitTester = &a;
}
