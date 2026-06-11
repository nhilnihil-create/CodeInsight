#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define N 100005
#define inf (1ll << 60)
int n, A[N], B[N];
ll ans, s[N], t[N], now, tot;
int main()
{
	scanf("%d", &n);
	scanf("%lld", &ans);
	t[0] = ans;
	char opt[5];
	for (int i = 1; i < n; i++)
	{
		scanf("%s%d", opt, &A[i]);
		B[i] = opt[0] == '+' ? 1 : -1;
		ans += A[i] * B[i];
	}
	for (int i = n; i >= 1; i--)
		s[i] = A[i] + s[i + 1];
	for (int i = 1; i <= n; i++)
		t[i] = B[i] * A[i] + t[i - 1];
	now = -inf;
	tot = 0;
	for (int i = n; i >= 1; i--)
	{
		tot += A[i];
		if (B[i] == -1)
		{
			ans = max(ans, t[i - 1] - tot + now);
			now = s[i];
			tot = 0;
		}
	}
	printf("%lld\n", ans);
}
