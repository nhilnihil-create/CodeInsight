#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define endl "\n"

const int N = 55;
int x[N];
int cache[N][N][N * N];


int32_t main()
{
	IOS;
	int n, a;
	cin >> n >> a;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	//cache[1][1][0] = 1;
	cache[0][0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k <= 2500 - x[i + 1]; k++)
			{
				cache[i + 1][j + 1][k + x[i + 1]] += cache[i][j][k];
				cache[i + 1][j][k] += cache[i][j][k];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += cache[n][i][i * a];
	cout << ans << endl;
	return 0;
}