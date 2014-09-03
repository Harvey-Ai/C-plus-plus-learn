#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <iostream>
using namespace std;

/* Learning tips
 *
 * 1. Static variable need defined outside the class, it is declearation inside the class.
 * 2. Static var or function belongs to whole class. In a static function, no this pointer exists.
 * 3. Const static variable except integral var need initialized in parameter list.
 */

class singleton: public rawClass
{
	private:
		const int constInt;
		static singleton *m_pInstance;
		singleton(): constInt(1){}

	public:
		static singleton* getInstance();
		void doTest();
};

singleton* singleton::m_pInstance = NULL;

singleton* singleton::getInstance()
{
	if (m_pInstance == NULL)
		m_pInstance = new singleton();
	return m_pInstance;
}

void singleton::doTest()
{
	cout << endl;
	cout << "----------- singleton test -----------" << endl;
	singleton *p1 = singleton::getInstance();
	cout << "get object by a singleton class: " << p1 << endl;
	singleton *p2 = singleton::getInstance();
	cout << "get object by a singleton class: " << p2 << endl;
	cout << "p1 == p2 ? " << (p1 == p2 ? "YES" : "NO") << endl;
}

#endif

