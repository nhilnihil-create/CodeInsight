#include <bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define pr(x) printf("%d\n", x)
#define lowbit(x) (x & -x)
#define ll long long
#define memset(x) memset(x, 0, sizeof(x))
#define fre freopen(FILE".in", "r", stdin); freopen(FILE".out", "w", stdout);
#define FILE ""
using namespace std;
const int N = 100010;
int tot = 0, head[N], sum, n, k, ans = 9999999;
struct txljjkyzy
{
	int next, to;
}e[N * 2];
void add(int x, int y)
{
	e[++tot].to = y;
	e[tot].next = head[x];
	head[x] = tot;
}
void dfs(int x, int fa, int d)
{
	if (d > k / 2) return;
	sum++;
	for (int i = head[x]; i; i = e[i].next)
	{
		int y = e[i].to;
		if (y == fa) continue;
		dfs(y, x, d + 1);
	}
}
int main()
{
//	fre;
	sc(n);
	sc(k);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		sc(x);
		sc(y);
		add(x, y);
		add(y, x);
	}
	if (k % 2 == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			sum = 0;
			dfs(i, 0, 0);
			ans = min(ans, n - sum);
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		for (int j = head[i]; j; j = e[j].next)
		{
			int y = e[j].to;
			sum = 0;
			dfs(i, y, 0);
			dfs(y, i, 0);
			ans = min(ans, n - sum);
		}
	}
	cout << ans << endl;
	return 0;
}
