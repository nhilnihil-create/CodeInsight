#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 100000;

inline int gcd(int a, int b)
{
	while (b > 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

int n;
int a[MaxN];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		a[i] = getint();

	bool cur = false;
	while (true)
	{
		int o = 0, e = 0, k = 0;
		for (int i = 0; i < n; ++i)
			a[i] & 1 ? (++o, k = i) : ++e;

		if ((~e & 1) && o == 1)
		{
			if (a[k] == 1)
				break;

			int d = --a[k];
			for (int i = 0; i < n; ++i)
				d = gcd(d, a[i]);
			for (int i = 0; i < n; ++i)
				a[i] /= d;

			cur = !cur;
		}
		else
		{
			if (e & 1)
				cur = !cur;

			break;
		}
	}

	puts(cur ? "First" : "Second");

	return 0;
}