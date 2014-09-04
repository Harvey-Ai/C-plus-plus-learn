/*
 * myString.h
 *
 *  Created on: Aug 26, 2014
 *      Author: ufo008ahw
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_

#include <vector>
#include <cstring>
#include <iostream>
#include "rawTester.h"
using namespace std;


/* Learning tip: It is very good to write a string class by yourself, because it contains many
 * trape in it, you need consider what to return a pointer, common or a citation type, and it
 * need a const qualifier? and so on.
 *
 * 1. The copy construct function's parameter must be a citation type, in case of endless call.
 * 2. Use const parameter as much as possible, because non-constant argument can call
 * const parameter, such as myString(const myString &str) can accept temporary var,
 * otherwise not.
 * 3. Copy citation variable if the object is large, in such case can escape copy excution.
 * 4. Return citation variable if there need consecutive operation, or assignment.
 * 5. It need carefully check the self-copy or NULL pointer.
 *
 */

class myString
{
	private:
		int m_len;
		vector<char> m_str;

	public:
		myString(){ m_len = 0; };
		~myString(){}
		myString(const char* cStr);
		myString(const myString &str);

		const char operator[](int index) const;
		char& operator[](int index);
		myString operator+(const myString &str);
		myString& operator=(const myString &str);
		bool operator==(const myString &str);

		friend ostream& operator << (ostream &out, const myString &str);
		friend istream& operator >> (istream &in, myString &str);

		void doTest();
};

myString::myString(const char* cStr)
{
	if (cStr == NULL)
	{
		m_len = 0;
		return;
	}

	int vectorSize = m_str.size() < 1 ? 1 : m_str.size();
	m_len = strlen(cStr);

	while(vectorSize < m_len)
		vectorSize *= 2;
	if (vectorSize != m_str.size())
		m_str.resize(vectorSize);

	for(int i = 0;i < m_len;i++)
		m_str[i] = cStr[i];
}

myString::myString(const myString& str)
{
	m_len = str.m_len;
	int vecSize = m_str.size() < 1 ? 1 : m_str.size();

	while (vecSize < m_len)
		vecSize *= 2;
	if (m_str.size() != vecSize)
		m_str.resize(vecSize);

	for(int i = 0;i < m_len;i++)
		m_str[i] = str[i];
}

const char myString::operator[](int index) const
{
	return (const char)m_str[index];
}

char &myString::operator[](int index)
{
	return m_str[index];
}

myString myString::operator +(const myString& str)
{
	myString newStr;
	newStr.m_len = m_len + str.m_len;
	newStr.m_str.resize(m_len);

	for(int i = 0;i < m_len;i++)
		newStr[i] = m_str[i];

	for(int i = m_len;i < newStr.m_len;i++)
		newStr[i] = str.m_str[i - m_len];

	return newStr;
}

myString& myString::operator=(const myString &str)
{
	if (&str == this)
		return *this;

	m_len = str.m_len;

	int vecSize = m_str.size() < 1 ? 1 : m_str.size();
	while (vecSize < m_len)
		vecSize *= 2;
	if (m_str.size() != vecSize)
		m_str.resize(vecSize);

	for(int i = 0;i < str.m_str.size();i++)
		m_str[i] = str[i];

	return *this;
}

bool myString::operator==(const myString &str)
{
	if (str.m_len != m_len)
		return false;

	for(int i = 0;i < m_len;i++)
		if (str[i] != m_str[i])
			return false;
	return true;
}


ostream& operator << (ostream &out, const myString &str)
{
	for(int i = 0;i < str.m_len;i++)
		out << str[i];
	return out;
}

istream& operator >> (istream &in, myString &str)
{
	str.m_len = 0;
	int c;
	while((c = in.get()))
		str.m_str[str.m_len++] = c;
	return in;
}

////////////////////////////
class myStringTester: public rawTester
{
	public:
		void doTest();
};


void myStringTester::doTest()
{

	cout << endl;
	cout << "----------- My string test -----------" << endl;

	char *p = (char*)malloc(100);
	p[0] = '0';p[1] = '1';p[2] = '\0';
	myString *p3 = new myString(p);
	myString *p1 = new myString("myNew string");
	cout << "myString = " << *p1 << ", " << ((*p1 == "myNew string") ? "YES" : "NO") << endl;
	cout << "myString[0] = " << (*p1)[0] << ", " << (((*p1)[0] == 'm') ? "YES" : "NO") << endl;
	(*p1)[0] = 'y';
	cout << "character assign, myString[0] = " << (*p1)[0] << ", " << (((*p1)[0] == 'y') ? "YES" : "NO") << endl;
	(*p1) = "myNew string";
	cout << "myString + \" haha\" = " << (*p1 + " haha") << ", " << (((*p1 + " haha") == "myNew string haha") ? "YES" : "NO") << endl;

	myString *p2 = new myString(*p1);
	cout << "copy construction myString2 = " << *p2 << ", " << ((*p2 == "myNew string") ? "YES" : "NO") << endl;
	*p2 = *p1;
	cout << "copy assignment myString2 = " << *p2 << ", " << ((*p2 == "myNew string") ? "YES" : "NO") << endl;
	cout << endl;
}

#endif /* MYSTRING_H_ */
