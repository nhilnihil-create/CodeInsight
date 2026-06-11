#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 210, M = 10, INF = 0x3f3f3f3f;

int n, m, k;
int f[N][N];
int r[M];

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < k; i ++ ) cin >> r[i];
	
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			if (i == j) f[i][j] = 0;
			else f[i][j] = INF;
	
	for (int i = 0; i < m; i ++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		f[a][b] = f[b][a] = min(f[a][b], c);
	}
	
	for (int k = 1; k <= n; k ++ )
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= n; j ++ )
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	
	int res = INF;
	sort(r, r + k);
	do
	{
		int t = 0;
		for (int i = 0; i < k - 1; i ++ ) t += f[r[i]][r[i + 1]];
		res = min(res, t);
	}while (next_permutation(r, r + k));
	
	cout << res << endl;
    return 0;
}