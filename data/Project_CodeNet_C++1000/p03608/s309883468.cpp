#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 210, M = 110, INF = 0x3f3f3f3f;

int n, m, k;
int g[N][N], r[N];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			if (i == j) g[i][j] = 0;
			else g[i][j] = INF;
			
	for (int i = 0; i < k; i ++ ) scanf("%d", &r[i]);
	sort(r, r + k);
			
	for (int i = 0; i < m; i ++ )
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	
	for (int k = 1; k <= n; k ++ )
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= n; j ++ )
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				
	// for (int i = 1; i <= n; i ++ )
	// {
		// for (int j = 1; j <= n; j ++ )
			// cout << g[i][j] << ' ';
		// puts("");
	// }
				
	int res = INF;	
	do
	{
		// for (int i = 0; i < k; i ++ ) cout << r[i] << ' ';
		// puts("");
		int sum = 0;
		for (int i = 1; i < k; i ++ ) sum += g[r[i]][r[i - 1]];
		res = min(res, sum);
	}while(next_permutation(r, r + k));
	
	printf("%d\n", res);
	return 0;
}
