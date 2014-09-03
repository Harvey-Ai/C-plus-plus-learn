#include <iostream>
#include "rawClass.h"
using namespace std;


/* Learning tips : be careful of the type conversion in C.
 *
 * 1. In the "? :" operation, the result type is depend on both last two operands.
 *
 */


class basicGram: public rawClass
{
	private:

	public:
		void doTest();
};

void basicGram::doTest()
{
	cout << endl;
	cout << "----------- basic grammer test -----------" << endl;
	cout << "sizeof(1 > 0 ? 1 : 0) = " << sizeof(1 > 0 ? 1 : 0) << ", " \
			<< (sizeof(1 > 0 ? 1 : 0) == sizeof(int) ? "YES" : "NO") << endl;
	cout << "sizeof(1 > 0 ? 1 : 0.0) = " << sizeof(1 > 0 ? 1 : 0.0) << ", " \
			<< (sizeof(1 > 0 ? 1 : 0.0) == sizeof(double) ? "YES" : "NO") << endl;
}
