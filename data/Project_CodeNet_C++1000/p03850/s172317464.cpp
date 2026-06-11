#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

inline char nextChar()
{
	static char c;
	while ((c = getchar()) != '+' && c != '-');

	return c;
}

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

const int MaxN = 100000;
const s64 INF = 0x3f3f3f3f3f3f3f3fll;

int n;

s64 f0, f1, f2;

int main()
{
	cin >> n;

	f0 = getint();
	f1 = f2 = -INF;
	for (int i = 1; i < n; ++i)
	{
		if (nextChar() == '+')
		{
			int v = getint();
			f0 += v, f2 += v;
			f1 -= v;
		}
		else
		{
			int v = getint();
			f0 -= v, f2 -= v;
			f1 += v;

			relax(f2, f1);
			relax(f1, f0);
		}

		relax(f1, f2);
		relax(f0, f1);
	}

	cout << f0 << endl;

	return 0;
}