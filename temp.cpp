#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

template<class T>
T getPrimes(T m, vector<T>& primes)
{
	primes.resize(0);

	T primeNum = 1;
	primes.push_back(2);

	for(T i = 3;i < m;i += 2)
	{
		bool isPrime = true;
		for(T j = 0;j < primeNum && primes[j] * primes[j] <= i;j++)
			if (i % primes[j] == 0)
			{
				isPrime = false;
				break;
			}
		if (isPrime)
		{
			primeNum++;
			primes.push_back(i);
		}
	}
	return primeNum;
}

template<>
int getPrimes(int n, vector<int> &a)
{
}

int main()
{
	return 0;
}
