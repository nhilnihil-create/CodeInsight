#include <bits/stdc++.h>

const int N = 100005;
const long long INF = (long long)1e15;

long long f[N][3];
char op[N][2];

int n,a[N];

int main()
{
	scanf("%d",&n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%s",&a[i],op[i]);
	}
	scanf("%d",&a[n]);
	f[1][0] = a[1], f[1][1] = f[1][2] = -INF;
	for (int i = 2; i <= n; i++)
	{
		if (op[i - 1][0] == '+')
		{
			f[i][0] = std::max(f[i - 1][0], f[i - 1][1]) + a[i];
			f[i][1] = f[i - 1][1] - a[i];
			f[i][2] = f[i - 1][2] + a[i];
		}
		if (op[i - 1][0] == '-')
		{
			f[i][0] = -INF;
			f[i][1] = std::max(f[i - 1][0], f[i - 1][1]) - a[i];
			f[i][2] = std::max(f[i - 1][1], f[i - 1][2]) + a[i];
		}
	}
	printf("%lld\n",std::max(std::max(f[n][0], f[n][1]), f[n][2]));
}