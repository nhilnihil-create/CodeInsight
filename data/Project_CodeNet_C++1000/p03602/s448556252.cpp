#include <bits/stdc++.h>
using namespace std;
#define maxn 400
#define int long long
int n, dis[maxn][maxn], Map[maxn][maxn];
int ans, mark[maxn][maxn];

int read()
{
	int x = 0, k = 1;
	char c; c = getchar();
	while(c < '0' || c > '9') { if(c == '-') k = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * k; 
}

signed main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			dis[i][j] = dis[j][i] = read();
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
			{
				if(dis[i][k] + dis[k][j] < dis[i][j]) { puts("-1"); return 0; }
				if(dis[i][k] + dis[k][j] == dis[i][j] && i != k && j != k) mark[i][j] = 1;
			}
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j ++) 
			if(!mark[i][j]) ans += dis[i][j];
	printf("%lld\n", ans);
	return 0;
}