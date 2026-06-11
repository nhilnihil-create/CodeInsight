#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 10;
typedef long long ll;
ll ans;
int n;
int d[maxn][maxn];
bool vis[maxn][maxn];
void floyd()
{
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(i != k && j != k)
				{
					if(d[i][j] == d[i][k] + d[k][j])
						vis[i][j] = 1;
					else if(d[i][j] > d[i][k] + d[k][j])
					{
						puts("-1");
						exit(0);
					}
				}
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(!vis[i][j])
				ans += d[i][j];
	printf("%lld\n", ans);
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &d[i][j]);
	floyd();
	return 0;
}