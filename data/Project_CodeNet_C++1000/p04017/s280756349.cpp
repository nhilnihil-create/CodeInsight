#include <bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define pr(x) printf("%d\n", x)
#define lowbit(x) (x & -x)
#define ll long long
#define N 100010
#define memset(x) memset(x, 0, sizeof(x))
using namespace std;
int n, a[N], f[N][35], l, q;
int main()
{
	//freopen("trav.in", "r", stdin);
	//freopen("trav.out", "w", stdout);
	sc(n);
	for (int i = 1; i <= n; i++)
	sc(a[i]);
	sc(l);
	for (int i = 1; i <= n; i++)
	{
		int id = (int)(upper_bound(a + 1, a + n + 1, a[i] + l) - a - 1);
		f[i][0] = id;
	}
	for (int j = 1; j <= 30; ++j)
	for (int i = 1; i <= n; ++i)
	f[i][j] = f[f[i][j - 1]][j - 1];
	sc(q);
	while (q--)
	{
		int x, y;
		sc(x);
		sc(y);
		if (x > y) swap(x, y);
		int sum = 1;
		for (int i = 30; i >= 0; i--)
		if (f[x][i] < y)
		{
			sum += 1 << i;
			x = f[x][i];
		}
		printf("%d\n", sum);
	}
	return 0;
}
