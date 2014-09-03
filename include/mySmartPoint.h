/*
 * mySmartPoint.h
 *
 *  Created on: Aug 26, 2014
 *      Author: ufo008ahw
 */

#ifndef MYSMARTPOINT_H_
#define MYSMARTPOINT_H_

#include "rawClass.h"

/* Learning tip: smart pointer mimic the garbage retrieve in Java.
 *
 * 1. Smart point only used for the heap object, it is to encapsulate the storage in heap.
 * 2. If object is on the stack, don't use smart point.
 *
 */

template<class T>
class mySmartPoint: public rawClass
{
	private:
		T *obj;
		int citeNum;

	public:
		mySmartPoint(T*);
		~mySmartPoint();

		mySmartPoint& operator=(const mySmartPoint& p);
};

#endif /* MYSMARTPOINT_H_ */
