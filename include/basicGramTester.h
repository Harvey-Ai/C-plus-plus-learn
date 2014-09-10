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

namespace basicGram
{

class fatherClass
{
	public:
		int a;
		fatherClass(){
			a = 10;
		};
		virtual int fa() { return 2; }
};

class derivedClass: public fatherClass
{
	public:
		//int b;
};

}


void basicGramTester::doTest()
{
	cout << endl;
	cout << "----------- basic grammer test -----------" << endl;
	// 1. Be careful of the type conversion in C. in the "? :" operation, the result type is
	//		depend on both last two operands.
	cout << "sizeof(1 > 0 ? 1 : 0) = " << sizeof(1 > 0 ? 1 : 0) << ", " \
			<< (sizeof(1 > 0 ? 1 : 0) == sizeof(int) ? "YES" : "NO") << endl;
	cout << "sizeof(1 > 0 ? 1 : 0.0) = " << sizeof(1 > 0 ? 1 : 0.0) << ", " \
			<< (sizeof(1 > 0 ? 1 : 0.0) == sizeof(double) ? "YES" : "NO") << endl;

	// 2. View the typedef as a variable declaration.
	basicGramTester::intType intValue;
	cout << "basicGramTester::intType intValue, sizeof(intValue) = " << sizeof(intValue) << ", " \
			<< (sizeof(int) == sizeof(intValue) ? "YES" : "NO") << endl;

	// 3. The #if condition compilation is calculated in the pre_process part, so ordinary variable
	// 		can't work in the #if, even the sizeof operator.
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

	// 6. static_cast, reinterpret_cast, const_cast, dynamic_cast
	// 1) Static_cast: upercasting in class, basic type casting,
	//					pointer between void and origin, and add const.
	// 2) Reinterpret_cast: convert pointer or reference, it interpret types in bit model, not type itself,
	// 					that means not bit loss in convert. This one is unsafe;
	// 3) Const_cast: convert pointer or reference, and remove their const qualifer.
	// 4) Dynamic_cast: convert father class to derived class, this cast has ability type check function
	//					during run time, so it need a virtual table to determine the type.
	//					It safer than static_cast. !But it may crash in run-time.
	basicGram::fatherClass myFather;
	basicGram::derivedClass myDerive;

	// static_cast mainly used for basic
	int b = 10;
	double c = static_cast<double>(b);
	cout << "static_cast b, b = " << c << ", " << (c == 10.0 ? "YES" : "NO") << endl;
	static_cast<void*>(&c);
	static_cast<const int>(c);
	static_cast<const double *>(&c);
	// ！ static_cast can't cast different pointer except void *
	// static_cast<const int *>(&c);

	// reinterpret_cast is very dangerous, it is mainly used for converting different pointers.
	double d = reinterpret_cast<double &> (b);
	cout << "reinterpret_cast b = " << d << ", " << (d == b ? "NO" : "YES") << endl;
	double *pb = reinterpret_cast<double *> (&b);

	// const_cast is used for remove the const qualifer.
	const int f = 10;
	const_cast<int &>(f);
	const_cast<int *>(&f);

	// dynamic_cast if used for downcasting, it is safer than static_cast.
	// Virtual function is needed; !But it may crash in run-time.
	// myDerive = dynamic_cast<basicGram::derivedClass &>(myFather);
	 cout << "myDerive.a = " << myDerive.a << ", " << (myDerive.a == 10 ? "YES" : "NO") << endl;
}
