#include <bits/stdc++.h>
using namespace std;
int hat[100500], n = 0;
int x = 0, y = 0;
int tx = 0, ty = 0;
signed main()
{
	scanf("%d", &n), x = n;
	for(int i = 1; i <= n; i++)
		scanf("%d", hat + i), x = min(hat[i], x), y = max(hat[i], y);
	if(x + 1 < y) return (puts("No"), 0);
	for(int i = 1; i <= n; i++)
	{
		if(hat[i] == x) tx++;
		if(hat[i] == y) ty++;
	}
	if(x == y)
	{
		if(x == n - 1 || x <= n / 2) return (puts("Yes"), 0);
		else return (puts("No"), 0);
	}
	else
	{
		if(y <= tx) return (puts("No"), 0);
		if(n < 2 * (y - tx) + tx) return (puts("No"), 0);
		else return (puts("Yes"), 0);
	}
	return 0;
}