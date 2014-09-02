#include <iostream>
#include <vector>
#include "rawClass.h"
using namespace std;

class STL:public rawClass
{
	private:
	public:
		void doTest();
};

void STL::doTest()
{
	vector<int> ha(10);
	ha[0] = 100;
	ha[1] = 1;
	vector<int>::iterator b;
	b = ha.begin();
	b++;
	cout << *b << endl;
	ha.insert(ha.begin(), 1, 20);
	cout << *b << endl;
	cout << b - ha.begin() << endl;
}
