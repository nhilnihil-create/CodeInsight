#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;

int dp[101][100][301];
int w[100];
int v[100], vsort[100];

int main()
{
	int N, W, base;
	int ans = 0;

	cin >> N >> W;
	rep(i, N) cin >> w[i] >> v[i];
	rep(i, N) vsort[i] = v[i];
	sort(vsort, vsort + N, greater<int>());

	base = w[0];
	rep(i, N) w[i] -= base;

	repc(num, 1, N) {
		repc(n, 0, num) rep(i, N) rep(j, 301) dp[n][i][j] = 0;

		int WW = W - base * num;
		if (WW < 0) break;
		else if (WW > 300) {
			int sum = 0;
			rep(i, num) sum += vsort[i];
			ans = max(ans, sum);
			continue;
		}

		repc(n, 1, num) rep(i, N) repc(j, 0, WW) {
			if (n == 1) {
				if (i == 0) dp[n][i][j] = v[i];
				else {
					dp[n][i][j] = dp[n][i - 1][j];
					if (w[i] <= j) dp[n][i][j] = max(dp[n][i][j], v[i]);
				}
			}
			else if (i == 0) continue;
			else {
				dp[n][i][j] = max(dp[n][i][j], dp[n][i - 1][j]);
				if (j >= 1) dp[n][i][j] = max(dp[n][i][j], dp[n][i][j - 1]);
				if (j >= w[i]) dp[n][i][j] = max(dp[n][i][j], dp[n - 1][i - 1][j - w[i]] + v[i]);
			}
		}

		ans = max(ans, dp[num][N - 1][WW]);
	}

	cout << ans << endl;

	return 0;
}
