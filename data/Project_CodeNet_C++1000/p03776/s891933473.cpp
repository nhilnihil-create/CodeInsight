#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr i64 MOD = 1000000007;
constexpr i64 INF = 1LL << 60;

int main() {
	i64 n, a, b; cin >> n >> a >> b;
	double* v = new double[n];
	rep(i, 0, n) cin >> v[i];

	sort(v, v + n);

	i64 maxcnt = 0;
	i64 maxcnt_all = 0;
	double maxave = 0.0;
	rep(i, 0, a) {
		maxave += v[n - 1 - i];
		if (v[n - 1 - i] == v[n - a]) ++maxcnt;
	}
	maxave /= a;

	rep(i, 0, n) if (v[i] == v[n - a]) {
		++maxcnt_all;
	}

	vector<vector<i64>> dp(99, vector<i64>(99, 0));
	dp[0][0] = 1;
	rep(i, 0, 60) 
		rep(j, 0, i + 1) {
		dp[i + 1][j] += dp[i][j];
		dp[i + 1][j + 1] += dp[i][j];
	}

	i64 ans = 0;
	if (maxcnt == a) {
		rep(i, a, min(b, maxcnt_all) + 1) ans += dp[maxcnt_all][i];
	}
	else {
		ans = dp[maxcnt_all][maxcnt];
	}

	cout << fixed << setprecision(10) << maxave << endl;
	cout << ans;

	delete[] v;
	return 0;
}