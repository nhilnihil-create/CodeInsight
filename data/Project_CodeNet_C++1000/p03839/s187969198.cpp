/**
*    author:  boutarou
*    created: 18.06.2020 23:06:11
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define fcout cout << fixed << setprecision(15)
using lint = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const double PI = 3.1415926535897932;

int n, k;
lint a[100005];
lint all_sum[100005], pl_sum[100005];
lint ans = 0;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> k;
	rep(i, n) cin >> a[i];
	all_sum[0] = 0, pl_sum[0] = 0;
	rep(i, n) {
		all_sum[i + 1] = all_sum[i] + a[i];
		pl_sum[i + 1] = pl_sum[i] + (a[i] >= 0 ? a[i] : (lint)0);
	}
	for (int i = 0; i <= n - k; i++) {
		chmax(ans, pl_sum[n] - (pl_sum[i + k] - pl_sum[i]));
		chmax(ans, pl_sum[n] - (pl_sum[i + k] - pl_sum[i]) + (all_sum[i + k] - all_sum[i]));
	}
	cout << ans << endl;
	
	return 0;
}