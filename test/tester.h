#include <vector>
#include "../include/rawClass.h"
#include "../include/operatorNew.h"
#include "../include/singleton.h"
#include "../include/constPointer.h"
#include "../include/cFunctionCompileCall.h"
#include "../include/unInheritedClass.h"
#include "../include/classStorage.h"
#include "../include/myString.h"
#include "../include/basicGram.h"
#include "../include/unInheritedClass.h"
#include "../include/templateConcept.h"
#include "../include/mySmartPoint.h"
#include "../include/STL.h"
using namespace std;

static vector<rawClass*> testers;
static void loadTester()
{
	// C
	testers.push_back(new basicGram);
	testers.push_back(new cFunctionCall);

	// OO
	testers.push_back(singleton::getInstance());
	testers.push_back(new constPointer());
	testers.push_back(new unInheritedClass);
	testers.push_back(new myString);

	// GP
	testers.push_back(new STL);
	testers.push_back(new templateConcept);

	// STORAGE
	testers.push_back(new classStorage);
	testers.push_back(new operatorNew);
	//testers.push_back(new mySmartPoint);
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
