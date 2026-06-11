#include <bits/stdc++.h>

using namespace std;
const int maxn = 500010, inf = 1e9 + 233;
int n, T;
int a[maxn], mn[maxn];

int main()
{
	scanf("%d%d", &n, &T);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	mn[0] = inf;
	for (int i = 1; i <= n; i++)
		mn[i] = min(mn[i - 1], a[i]);
		
	int mx = 0;
	for (int i = 2; i <= n; i++)
		mx = max(mx, a[i] - mn[i - 1]);
		
	int ans = 0;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] - mn[i - 1] == mx) ans++;
		//printf("%d %d\n", a[i], mn[i - 1]);
	}
		
	printf("%d\n", ans);
}