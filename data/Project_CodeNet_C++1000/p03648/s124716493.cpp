#include "bits/stdc++.h"
using namespace std;
int main()
{
	long long k, m, n = 50;
	scanf("%lld", &k);
	m = k / n;
	vector<long long> a(n, n - 1 + m);
	for(int i = k - n * m, j = 0; i > 0; --i, ++j)
	{
		a[j] += n;
		for(int k = 0; k < n; ++k)
		{
			if(k != j)
			{
				--a[k];
			}
		}
	}
	printf("%d\n", n);
	for(int i = 0; i < n; printf("%lld ", a[i++])){}
	printf("\n");
}