#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <map>
#include<cmath>
#include <queue>
#include <numeric>
#include <cassert>

using lli = long long int;
lli inf = 1000000007;
using namespace std;

void solve()
{
	int N, A;
	cin >> N >> A;
	vector<int> x(N);
	for (int i = 0; i < N; i++)cin >> x[i];
	lli dp[52][52][2540];
	dp[0][0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k <= 2500; k++) {
				dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
				dp[i + 1][j][k] += dp[i][j][k];
			}
		}
	}
	lli ans = 0;
	for (int j = 1; j <= N; j++) {
		ans += dp[N][j][j * A];
	}
	cout << ans << endl;
}

int main()
{
	solve();
	return 0;
}