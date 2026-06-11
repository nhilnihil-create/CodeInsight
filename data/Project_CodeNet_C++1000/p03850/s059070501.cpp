#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100010;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n, a[MAXN];
char op[MAXN][5];
ll f[MAXN][3];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) scanf("%d %s", &a[i], op[i]);
	scanf("%d", &a[n]);
	f[1][0] = a[1], f[1][1] = f[1][2] = -inf;
	for(int i = 2; i <= n; ++i)
	{
		if(op[i - 1][0] == '+')
		{
			f[i][0] = max(f[i - 1][0] + a[i], f[i - 1][1] + a[i]);
			f[i][1] = f[i - 1][1] - a[i];
			f[i][2] = f[i - 1][2] + a[i];
		}
		else
		{
			f[i][0] = -inf;
			f[i][1] = max(f[i - 1][0] - a[i], f[i - 1][1] - a[i]);
			f[i][2] = max(f[i - 1][1] + a[i], f[i - 1][2] + a[i]);
		}
	}
	printf("%lld\n", max(f[n][0], max(f[n][1], f[n][2])));
	return 0;
}