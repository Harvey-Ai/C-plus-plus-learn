/*
 * myInorderIterator.h
 *
 *  Created on: Aug 26, 2014
 *      Author: ufo008ahw
 */

#include <iostream>
#include <stack>
#include "rawTester.h"
using namespace std;

struct myTreeNode
{
	int val;
	myTreeNode *left, *right;

	myTreeNode(int v, myTreeNode *l = NULL, myTreeNode *r = NULL)
	{
		val = v;
		left = l;
		right = r;
	}
};

class myInorderIterator
{
	stack<myTreeNode *> treeStack;

	public:
		myInorderIterator(myTreeNode& oneTreeNode)
		{
			treeStack.push(&oneTreeNode);
			myTreeNode *currentNode = oneTreeNode.left;
			while(currentNode)
			{
				treeStack.push(currentNode);
				currentNode = currentNode->left;
			}
		}

		bool end()
		{
			return treeStack.empty();
		}
		int value()
		{
			return (treeStack.top())->val;
		}
		void operator++(int)
		{
			myTreeNode *currentNode = treeStack.top();
			treeStack.pop();

			if (currentNode->right != NULL)
			{
				currentNode = currentNode->right;
				while(currentNode)
				{
					treeStack.push(currentNode);
					currentNode = currentNode->left;
				}
			}
		}
};

class myInorderIteratorTester: public rawTester
{
	public:
		void doTest();
};


void myInorderIteratorTester::doTest()
{
	myTreeNode node3(3);
	myTreeNode node4(4);
	myTreeNode node5(5);
	myTreeNode node6(6);
	myTreeNode node1(1, &node3, &node4);
	myTreeNode node2(2, &node5, &node6);
	myTreeNode root(0, &node1, &node2);

	cout << endl;
	cout << "----------- myInorderIterator Tester -----------" << endl;
	cout << "Init tree:" << endl;
	cout << "     0\n"
		    "   /  \\ \n"
		    "  1     2 \n"
	        " / \\   / \\ \n"
		    "3   4 5   6\n";
	myInorderIterator myIterator(root);

	int answer[] = {3, 1, 4, 0, 5, 2, 6};
	for(int i = 0;!myIterator.end();i++)
	{
		if (myIterator.value() == answer[i])
			cout << myIterator.value() << " ";
		else
		{
			cout << "iterator error" << endl;
			break;
		}
		myIterator++;
	}
	if (myIterator.end())
		cout << "YES"<< endl;
	else
		cout << "NO"<< endl;

}
