#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

const int MaxN = 1000000;
const int M = 1000000007;

int n;

int f[MaxN + 1];
int g[MaxN + 1];

int main()
{
	cin >> n;

	f[1] = g[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (i >= 3)
			f[i] = g[i - 3];
		f[i] = (f[i] + f[i - 1]) % M;
		g[i] = (f[i] + g[i - 1]) % M;
	}

	int res = (s64)f[n] * n % M;
	for (int i = 1; i < n; ++i)
		res = (res + f[i] * ((s64)(n - 1) * (n - 1) % M + min(n - 1, i + 1))) % M;

	cout << res << endl;

	return 0;
}