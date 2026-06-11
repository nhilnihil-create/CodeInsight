#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

#define N 200008

int n;
int a[N];
long long sum = 0;

void solve()
{
	long long first = a[1];
	long long minn = abs(sum-first-first);
	for (int i = 2; i < n; i++)
	{
		first += (long long)a[i];
		minn = min(minn,abs(sum-first-first));
	}
	printf("%lld\n", minn);
}

void init()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum += (long long)a[i];
	}
}

int main()
{
	init();
	solve();
	return 0;
}