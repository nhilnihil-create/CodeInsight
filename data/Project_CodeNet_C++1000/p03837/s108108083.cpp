#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110, M = 1010, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
struct Edge
{
	int a, b, c;
}e[M];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			if (i == j) g[i][j] = 0;
			else g[i][j] = INF;
	
	for (int i = 0; i < m; i ++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		e[i] = {a, b, c};
		g[a][b] = g[b][a] = c;
	}
	
	for (int k = 1; k <= n; k ++ )
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= n; j ++ )
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				
	int res = 0;
	for (int i = 0; i < m; i ++ )
	{
		int a = e[i].a, b = e[i].b, c = e[i].c;
		if (c != g[a][b]) res ++ ;
	}
		
	cout << res << endl;
	return 0;
}