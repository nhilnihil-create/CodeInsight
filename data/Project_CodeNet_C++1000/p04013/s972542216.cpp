#pragma region
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define all(x) x.begin(),x.end()
#pragma endregion

ll dp[51][51][2501];

int main()
{
	int n, a; cin >> n >> a;
	vector<int> x(n);
	rep(i, n)cin >> x[i];
	rep(i, 51)rep(j, 51)rep(k, 2501)dp[i][j][k] = 0;
	dp[0][0][0] = 1;
	rep(i, n)rep(j, i + 1)rep(k, 2501)
	{
		dp[i + 1][j][k] += dp[i][j][k];
		if (k - x[i] >= 0)dp[i + 1][j + 1][k] += dp[i][j][k - x[i]];
	}
	ll res = 0;
	for (int i = 1; i <= n; ++i)res += dp[n][i][i * a];
	cout << res << endl;
}