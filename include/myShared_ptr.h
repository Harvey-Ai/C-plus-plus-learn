/*
 * mySmartPoint.h
 *
 *  Created on: Aug 26, 2014
 *      Author: ufo008ahw
 */

#ifndef MYSMARTPOINT_H_
#define MYSMARTPOINT_H_


template<class T>
class myhared_ptr
{
	private:
		T *obj;
		int citNum;

	public:
		mySmartPoint(T*);
		~mySmartPoint();

		mySmartPoint& operator=(const mySmartPoint& p);
}





#endif /* MYSMARTPOINT_H_ */
