#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <iostream>
using namespace std;

// 1. static variable need defined outside the class.
// 2. const variable except integral var need defined in parameter list

/* learning tips
 * 1. static variable need defined outside the class, it is
 * declearation inside the class.
 * 2. static var or function belongs to whole class. In a static function,
 * no this pointer exists.
 * 3. const static variable except integral var need initialized
 *  in parameter list.
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
	singleton *p1 = singleton::getInstance();
	singleton *p2 = singleton::getInstance();
	assert(p1 == p2);
}

#endif

