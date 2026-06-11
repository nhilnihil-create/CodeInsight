#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 55, M = 1010;

int n, m;
int a[N];
LL f[N][N][N * N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	
	for (int i = 0; i <= n; i ++ ) f[i][0][0] = 1;
	
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= i; j ++ )
			for (int k = 0; k < N * N; k ++ )
			{
				f[i][j][k] += f[i - 1][j][k];
				if (k >= a[i]) f[i][j][k] += f[i - 1][j - 1][k - a[i]];
			}
	
	LL res = 0;
	for (int i = 1; i <= n; i ++ ) res += f[n][i][i * m];
	cout << res << endl;
    return 0;
}