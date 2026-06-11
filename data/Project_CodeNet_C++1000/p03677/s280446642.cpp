#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100005;

int n,m,A[MAX_N];
long long x[MAX_N], add[MAX_N];

// x[a..b]++ und add[a..b] += c
void magic(int a, int b, int c)
{
	if (a > b)
		return;
	x[a]++;
	x[b+1]--;
	add[a] += c;
	add[b+1] -= c;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)
		scanf("%d",A+i);
	long long cost = 0;
	for (int i=1; i<n; i++)
	{
		int a = A[i], b = A[i+1];
		cost += (b-a+m)%m;
		if (a <= b)
			magic(a+1, b, -a-1); // a < x <= b: x - a - 1
		else
		{
			magic(a+1, m, -a-1); // a < x <= m:  x - a - 1
			magic(1, b, m-a-1);  // 1 <= x <= b: m - a + x - 1
		}
	}
	partial_sum(x, x+m+1, x);
	partial_sum(add, add+m+1, add);
	for (int i=1; i<=m; i++)
		x[i] = x[i]*i + add[i];
	printf("%lld\n", cost - *max_element(x+1, x+1+m));
	return 0;
}