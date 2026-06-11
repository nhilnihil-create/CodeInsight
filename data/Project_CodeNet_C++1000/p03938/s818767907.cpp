#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 10;
int n, Min, a[maxn], b[maxn], p[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) a[i] = 1, b[i] = -1;
	for(int i = 1; i <= n; ++i) 
	{
		scanf("%d", &p[i]);
		a[p[i]] += i;
		b[p[i] + 1] -= i;
	}
	for(int i = 1; i <= n; ++i) 
	{
		a[i] += a[i - 1];
		printf("%d ", a[i]);
		b[i] += b[i - 1];
		Min = min(Min, b[i]);
	}
	puts("");
	--Min;
	for(int i = 1; i <= n; ++i)
	{
		b[i] -= Min;
		printf("%d ", b[i]);
	}
	return 0;
}
	 