#include <iostream>
#include <sstream>
#include "rawTester.h"
using namespace std;


/* Learning tips: keyword: template implicit instantiate, explicit instantiate and explicit
 * specification.
 * class template, function template, partial specification and template's non-class type.
 *
 * 1. Instantiation is for generating the type or function, Specification is used for special
 * handle.
 * 2. Deduction only works on the parameters. No deduction about the returning type except returning type
 * has the same type with only of the parameters. So the class template need explicitly gives
 * the parameter type.
 * 3. In case of ambiguity, typename is used for the type declaration.
 * 4. ! Function partial is not allow on my compiler.
 * 5. Application will use oridinal -> partial specific -> specific -> instantiation, in all,
 * application use function will more restriction.
 *
 */


/// class template
template <class T1, class T2>
string myTemplateFunction(T1 a, T2 b)
{
	return "This is instantiation";
}

// Ordinary function will used first!
// string myTemplateFunction(double a, double b)
// {
//	return "I am ordinary function";
// }

// explicit instantiate
template string myTemplateFunction<double, double>(double a, double b);

// explicit specification
template<>
string myTemplateFunction<string, string>(string a, string b)
{
	return "This is explicit specification";
}

// partial specification, it is not mean some template parameters are specificated, it means another
// define of the template. SEE THE "typeTrait".
// template <class T>
// T myTemplateFunction<T, string>(T a, string b)
// {
//		return "This is partial specification";
// }

// non-class type
template <int n, class T>
string myTemplateFunction(T a, T b)
{
	stringstream ss;
	string s;
	ss << n;
	ss >> s;
	return "This is no-call type " + s;
}

template<class T>
struct typeTrait
{
	typedef T valueType;
	valueType value;

	typeTrait(T v)
	{
		value = v;
	}
};

// This is partial class template specification.
// Get the real value type & value.
template<class T>
struct typeTrait<T*>
{
	typedef T valueType;
	valueType value;

	typeTrait(T* v)
	{
		value = *v;
	}
};

template<class T>
class myTemplateClass
{
	private:
		typedef typename typeTrait<T>::valueType valueType;
		valueType value;

	public:
		myTemplateClass(T v);
		valueType output();
};

template<class T>
myTemplateClass<T>::myTemplateClass(T v)
{
	typeTrait<T> oneTraiter(v);
	value = oneTraiter.value;
}

template<class T>
typename myTemplateClass<T>::valueType myTemplateClass<T>::output()
{
	return value;
}

///////////////////////////
class templateConceptTester: public rawTester
{
	public:
		void doTest();
};

void templateConceptTester::doTest()
{
	cout << endl;
	cout << "----------- template Tester -----------" << endl;
	cout << myTemplateFunction(1.0, 1.0) << ", " << \
			(myTemplateFunction(1.0, 1.0) == "This is instantiation" ? "YES" : "NO") << endl;
	cout << myTemplateFunction(string("a"), string("a")) << ", " << \
			(myTemplateFunction(string("a"), string("a")) == "This is explicit specification" ? "YES" : "NO") << endl;
	cout << myTemplateFunction<100, string>("a", "b") << ", " << \
			(myTemplateFunction<100, string>("a", "b") == "This is no-call call 100" ? "YES" : "NO") << endl;

	int value = 100;
	myTemplateClass<int*> classInstance(&value);
	cout << "Value traiter = " << classInstance.output() << ", " << (classInstance.output() == 100 ? "YES" : "NO") << endl;
}
