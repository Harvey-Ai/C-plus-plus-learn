/*
 * mySmartPoint.h
 *
 *  Created on: Aug 26, 2014
 *      Author: ufo008ahw
 */

#ifndef MYSMARTPOINT_H_
#define MYSMARTPOINT_H_

#include "rawTester.h"

/* Learning tip: smart pointer mimic the garbage retrieve in Java.
 *
 * 1. Smart point only used for the heap object, it is to encapsulate the storage in heap.
 * 2. The storage layout is to use stack point to maintain the heap object.
 *
 */

template<class T>
class mySmartPoint
{
	private:
		int *citeNum;
		T *obj;

	public:
		mySmartPoint();
		mySmartPoint(T *obj);
		~mySmartPoint();

		int use_count();
		T* get();
		void reset();
		mySmartPoint& operator=(const mySmartPoint& p);
		T* operator->();
};

template<class T>
mySmartPoint<T>::mySmartPoint()
{
	this->obj = NULL;
	this->citeNum = NULL;
}

template<class T>
mySmartPoint<T>::mySmartPoint(T *obj)
{
	this->obj = obj;
	this->citeNum = new int(1);
}

template<class T>
mySmartPoint<T>::~mySmartPoint()
{
	if (this->obj != NULL)
	{
		(*citeNum)--;
		if (*citeNum == 0)
		{
			delete citeNum;
			delete obj;
			citeNum = NULL;
			obj = NULL;
		}
	}
}

template<class T>
int mySmartPoint<T>::use_count()
{
	return *citeNum;
}

template<class T>
T* mySmartPoint<T>::get()
{
	return this->obj;
}

template<class T>
void mySmartPoint<T>::reset()
{
	(*citeNum)--;
	if (*citeNum == 0)
	{
		delete obj;
		delete citeNum;
	}

	citeNum = NULL;
	obj = NULL;
}

template<class T>
mySmartPoint<T>& mySmartPoint<T>::operator=(const mySmartPoint& p)
{
	if (&p == this)
		return *this;

	if (citeNum != NULL && *citeNum != 0)
	{
		(*citeNum)--;
		if ((*citeNum) == 0)
		{
			delete citeNum;
			delete obj;
			citeNum = NULL;
			obj = NULL;
		}
	}

	citeNum = p.citeNum;
	obj = p.obj;
	(*citeNum)++;
}

template<class T>
T* mySmartPoint<T>::operator->()
{
	return this->obj;
}


////////////////////

class temp
{
	private:
		int value;
	public:
		temp(int v)
		{
			value = v;
		}
		int fun()
		{
			return value;
		}
};

class mySmartPointTester: public rawTester
{
	public:
		void doTest();
};

void mySmartPointTester::doTest()
{
	cout << endl;
	cout << "----------- My smart point Tester -----------" << endl;
	mySmartPoint<temp> onePoint1(new temp(100));
	mySmartPoint<temp> onePoint2;
	onePoint2 = onePoint1;
	cout << "SmartPoint point1 citeNum = " << onePoint1.use_count() << ", " <<
			(onePoint1.use_count() == 2 ? "YES" : "NO") << endl;
	cout << "SmartPoint point2 citeNum = " << onePoint2.use_count() << ", " <<
			(onePoint2.use_count() == 2 ? "YES" : "NO") << endl;

	cout << "SmartPoint point1 call fun return = " << onePoint1->fun() << ", " <<
			(onePoint1->fun() == 100 ? "YES" : "NO") << endl;
	cout << "SmartPoint point2 call fun return = " << onePoint2->fun() << ", " <<
			(onePoint2->fun() == 100 ? "YES" : "NO") << endl;
	onePoint1.reset();
	cout << "After reset, point1 = " << onePoint1.get() << ", " <<
			(onePoint1.get() == NULL ? "YES" : "NO") << endl;
	cout << "Point2 citeNum = " << onePoint2.use_count() << ", " <<
			(onePoint2.use_count() == 1 ? "YES" : "NO") << endl;

	mySmartPoint<temp> onePoint3(new temp(200));
	onePoint2 = onePoint3;
	cout << "After assignment point2 = point3, point1 = " << onePoint1.get() << ", " <<
			(onePoint1.get() == NULL ? "YES" : "NO") << endl;
	cout << "Point2 citeNum = " << onePoint2.use_count() << ", " <<
				(onePoint2.use_count() == 2 ? "YES" : "NO") << endl;
	cout << "Point2 value = " << onePoint2->fun() << ", " <<
			(onePoint2->fun() == 200 ? "YES" : "NO") << endl;
}


#endif /* MYSMARTPOINT_H_ */
