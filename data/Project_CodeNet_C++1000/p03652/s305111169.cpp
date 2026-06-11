#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 4005
#define inf 1e9
using namespace std;

inline int read()
{
	int x = 0, w = 1;char ch = getchar();
	while (ch > '9' || ch < '0') { if (ch == '-')w = -1;ch = getchar(); }
	while (ch >= '0' && ch <= '9')x = x * 10 + ch - '0', ch = getchar();
	return x * w;
}

int n, m, ans, maxans, pos, tmp;
int a[maxn][maxn], f[maxn], num[maxn], vis[maxn];

inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }

int main(void)
{
	n = read(), m = read();ans = inf;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			a[i][j] = read();
	for (int i = 1;i <= n;i++)
		num[i] = 1;
	for (int i = 1;i <= m;i++)
	{
		memset(f, 0, sizeof(f));
		maxans = 0;
		for (int j = 1;j <= n;j++)
		{
			f[a[j][num[j]]]++;
			if (f[a[j][num[j]]] > maxans)
			{
				maxans = f[a[j][num[j]]];
				pos = a[j][num[j]];
			}
		}
		vis[pos] = 1, ans = min(ans, maxans);
		for (int j = 1;j <= n;j++)
			while (vis[a[j][num[j]]]) num[j]++;
	}
	printf("%d\n", ans);
	return 0;
}