#include "bits/stdc++.h"
using namespace std;
long long a[200001];
int main()
{
	int n;
	long long mi = 1ll << 62;
	scanf("%d", &n);	
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
		a[i] += a[i - 1];
	}
	for(int i = 1; i < n; ++i)
	{
		mi = min(mi, abs(a[n] - a[i] - (a[i] - a[0])));
	}
	printf("%lld\n", mi);
}