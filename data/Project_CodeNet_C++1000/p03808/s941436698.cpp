#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N = 100009;
LL g[N], cnt, v, vn;
LL n;
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(LL i = 1; i <= n; i++)
		cin >> g[i], cnt += g[i];
	vn = n * (n + 1) / 2;
	if(cnt % vn)
	{
		puts("NO");
		return 0;
	}
	LL p = g[1];
	for(LL i = 1; i < n; i++)
		g[i] = g[i+1] - g[i];
	g[n] = p - g[n];
	LL d = cnt / vn;
	for(LL i = 1; i <= n; i++)
	{
		g[i] -= d;
		if(g[i] % n || g[i] > 0)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}