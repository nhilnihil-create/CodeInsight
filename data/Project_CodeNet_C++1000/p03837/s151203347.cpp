#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 110, M = 1010, INF = 0x3f3f3f3f;

int n, m;
int f[N][N];
struct Edge
{
	int a, b, c;
}e[M];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			if (i == j) f[i][j] = 0;
			else f[i][j] = INF;
			
	for (int i = 0; i < m; i ++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		e[i] = {a, b, c};
		f[a][b] = f[b][a] = min(f[a][b], c);
	}
	
	for (int k = 1; k <= n; k ++ )
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= n; j ++ )
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
				
	int res = 0;
	for (int i = 0; i < m; i ++ )
		if (e[i].c != f[e[i].a][e[i].b])
			res ++ ;
			
	cout << res << endl;
    return 0;
}