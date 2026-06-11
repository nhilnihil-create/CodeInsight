#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m;
bool a[maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		a[u] ^= 1;
		a[v] ^= 1;
	}
	for(int i = 1; i <= n; ++i)
		if(a[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}