#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define ll long long

// dp[i][j] : ホテルiからpow(2,j)日で移動できる最も右のホテル
int dp[100000][31];

// ホテルsからk日後にどのホテルに行くか
int get(int s, int k) {
	int h = s;
	for (int i = 0; i < 31; ++i)
		if ((1 << i) & k)
			h = dp[h][i];
	return h;
}

// ホテルsからホテルtまでの必要日数
int days(int s, int t) {
	if (s > t) return days(t, s);
	int ng = 0, ok = 1000000001;
	while (ok - ng > 1) {
		int mid = (ok + ng) / 2;
		if (get(s, mid) >= t) ok = mid;
		else ng = mid;
	}
	return ok;
}

signed main() {
	int n; cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	int l; cin >> l;

	/* dpを構築 */
	// j = 0を計算
	for (int i = 0; i < n; ++i) {
		auto iter = upper_bound(x.begin(), x.end(), x[i] + l);
		dp[i][0] = iter - x.begin() - 1;
	}
	// j > 0を構築
	for (int j = 1; j < 31; ++j)
		for (int i = 0; i < n; ++i)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		cout << days(--a, --b) << endl;
	}

	return 0;
}