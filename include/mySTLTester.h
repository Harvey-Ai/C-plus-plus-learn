#include <iostream>
#include <vector>
#include <map>
#include <boost/make_shared.hpp>
#include "rawTester.h"
using namespace std;


/* Learning tips : See below.
 */


class myClass
{
	private:
		int value;
	public:
		myClass(int v)
		{
			value = v;
		}
		int fun()
		{
			return value;
		}

};


///////////////////

class mySTLTester: public rawTester
{
	public:
		void doTest();
};

void mySTLTester::doTest()
{
	cout << endl;
	cout << "----------- STL test -----------" << endl;

	// 1. Vector iterator's trap. Any operation cause vector reallocte, like insert, resize and others, will make current
	// iterator ineffective. But this kind of thing don't happen on List.
	vector<int> myVector(10, 1);
	vector<int>::iterator it = myVector.begin();
	// insert one element 2 in myVector's beginning
	myVector.insert(it, 1, 2);
	cout << "After insert, (myVector.begin() == it) = " << (myVector.begin() == it) \
			<< ", " << (myVector.begin() != it ? "YES" : "NO") << endl;
	it = myVector.begin();
	myVector.resize(100);
	cout << "After resize, (myVector.begin() == it) = " << (myVector.begin() == it) \
			<< ", " << (myVector.begin() != it ? "YES" : "NO") << endl;

	// 2. Smart point: SEE mySmartPointTester.h
	boost::shared_ptr<myClass> sp1(new myClass(1));
	boost::shared_ptr<myClass> sp2 = sp1;

	// shared pointer
	cout << "Shared_ptr call member function return = " << sp1->fun() << ", "
			<< (sp1->fun() == 1 ? "YES" : "NO") << endl;
	cout << "Shared_ptr use_count must equal 2" << endl;
	cout << "Sp1 use_count = " << sp1.use_count() << ", " << (sp1.use_count() == 2 ? "YES" : "NO") << endl;
	cout << "Sp2 use_count = " << sp2.use_count() << ", " << (sp2.use_count() == 2 ? "YES" : "NO") << endl;
	sp2.reset();
	cout << "After sp2.reset(), means sp2 not in use" << endl;
	cout << "Sp1 use_count = " << sp1.use_count() << ", " << (sp1.use_count() == 1 ? "YES" : "NO") << endl;

	// auto pointer
	auto_ptr<myClass> ap1(new myClass(1));
	cout << "Auto_ptr call member function" << sp1->fun() << ", "
			<< (ap1->fun() == 1 ? "YES" : "NO") << endl;
	auto_ptr<myClass> ap2 = ap1;
	cout << "After assignment, means transport the management power" << endl;
	cout << "ap1 = " << ap1.get() << ", " << (ap1.get() == NULL ? "YES" : "NO") << endl;
	cout << "ap2 = " << ap2.get() << ", " << (ap2.get() != NULL ? "YES" : "NO") << endl;

	// 3. Make pair, pair is a struct in STL, map are constructed by those.
	pair<int, double> p1;
	p1 = make_pair(1, 1.1);
	cout << p1.first << " " << p1.second << "YES" << endl;
	map<int, double> intMap;
	intMap.insert(p1);
	cout << "Map value = " << intMap[p1.first] << ", "
			<< (intMap[p1.first] == p1.second ? "YES" : "NO") << endl;
}
