#include <iostream>
#include <vector>
#include "rawClass.h"
using namespace std;


/* Learning tips : In vector, insert, erase and resize operation will make the vector's iterator
 * ineffective, it is because of the "memory relocate". But this kind of thing don't happen on List.
 *
 * 1. In nature, operation which will resize the vector will make the previous iterator ineffective.
 */

class STL:public rawClass
{
	private:
	public:
		void doTest();
};

void STL::doTest()
{
	cout << endl;
	cout << "----------- STL test -----------" << endl;
	vector<int> myVector(10, 1);
	vector<int>::iterator it = myVector.begin();
	// insert one element 2 in myVector's beginning
	myVector.insert(it, 1, 2);
	cout << "after insert, (myVector.begin() == it) = " << (myVector.begin() == it) \
			<< ", " << (myVector.begin() != it ? "YES" : "NO") << endl;
	it = myVector.begin();
	myVector.resize(100);
	cout << "after resize, (myVector.begin() == it) = " << (myVector.begin() == it) \
			<< ", " << (myVector.begin() != it ? "YES" : "NO") << endl;
}
