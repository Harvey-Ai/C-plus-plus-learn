#include "rawClass.h"
using namespace std;


/* Learning tips: template implicit instantiate, explicit instantiate, implicit specification,
 * and explicit specification.
 * partial specification, template's non-class type.
 *
 * 1. Instantiation is for generating the type or function, Specification is used for special
 * handle.
 * 2. Deduction only works on the parameters. No deduction about the returning type except returning type
 * has the same type with only of the parameters.
 * 3. In case of ambiguity, typename is used for the type declaration.
 *
 */


template <class T1, class T2>
double add(T1 a, T2 b)
{
	//T1::valueType a;
	//T2::valueType b;
	return (double)(a + b);
}


class templateConcept : public rawClass
{
	private:
	public:
		void doTest();
};

void templateConcept::doTest()
{
	cout << endl;
	cout << "----------- Template concept test -----------" << endl;
//	template class mytemplateClass<char>;
	//cout << "explicit instantiated template size = " << sizeof(myExplicitClass) << ", " \
			<< (sizeof(mytemplateClass) == sizeof(mytemplateClass<char> ? "YES" : "NO") << endl;


}
