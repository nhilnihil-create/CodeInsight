#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int b[maxn];
int main()
{
	int n, x;
	scanf("%d%d", &n, &x);
	if(x == 1 || x == 2 * n - 1) 
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i = 1; i <= 2 * n - 1; ++i) b[i] = i;
	if(x > n)
	{
		b[n] = x;
		b[n + 1] = x + 1;
		int cnt = n;
		for(int i = n + 2; i <= 2 * n - 1; ++i)
		{
			while(cnt == x || cnt == x + 1) ++cnt;
			b[i] = cnt;
			++cnt;
		}
	}
	else
	{
		b[n] = x;
		b[n - 1] = x - 1;
		int cnt = 1;
		for(int i = 1; i <= n - 2; ++i)
		{
			while(cnt == x || cnt == x - 1) ++cnt;
			b[i] = cnt;
			++cnt;
		}
	}
	for(int i = 1; i <= 2 * n - 1; ++i) printf("%d ", b[i]);
	puts("");
	return 0;
} 