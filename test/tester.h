#include <vector>
#include "../include/rawTester.h"
#include "../include/operatorNewTester.h"
#include "../include/singletonTester.h"
#include "../include/cFunctionCompileCallTester.h"
#include "../include/unInheritedClassTester.h"
#include "../include/classStorageTester.h"
#include "../include/myStringTester.h"
#include "../include/basicGramTester.h"
#include "../include/templateConceptTester.h"
#include "../include/mySmartPointTester.h"
#include "../include/mySTLTester.h"
#include "../include/myInorderIterator.h"
#include "../include/exceptionHandlerTester.h"
using namespace std;

static vector<rawTester*> testers;
static void loadTester()
{
	// C
	testers.push_back(new basicGramTester);
	testers.push_back(new cFunctionCallTester);
	testers.push_back(new myInorderIteratorTester);

	// OO
	testers.push_back(new singletonTester);
	testers.push_back(new unInheritedClassTester);
	testers.push_back(new myStringTester);

	// GP
	testers.push_back(new mySTLTester);
	testers.push_back(new templateConceptTester);

	// STORAGE
	testers.push_back(new classStorageTester);
	testers.push_back(new operatorNewTester);
	testers.push_back(new mySmartPointTester);

	// EXCEPTION
	testers.push_back(new exceptionHandlerTester);
}

static void doTest()
{
	for(int i = 0;i < testers.size();i++)
		testers[i]->doTest();
}

static void deleteTester()
{
	for(int i = 0;i < testers.size();i++)
		delete testers[i];
	testers.clear();
}
