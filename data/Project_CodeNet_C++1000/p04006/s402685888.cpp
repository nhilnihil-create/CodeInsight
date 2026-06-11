#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <limits>
#include <sstream>
#include <typeinfo>
#include <cstdint>

using namespace std;

typedef long long ll;

int main() {
	int N;
	ll X;
	cin >> N >> X;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	vector<vector<ll>> dp(N, vector<ll>(N));
	ll ans = 1LL << 62LL;
	ll tmp = 0;
	for (int i = 0; i < N; i++) {
		dp[i][0] = a[i];
		tmp += dp[i][0];
	}
	ans = min(ans, tmp);
	for (int k = 1; k < N; k++) {
		ll tmp = k*X;
		for (int i = 0; i < N; i++) {
			const int idx = (i + N - k) % N;
			dp[i][k] = min(dp[i][k - 1], a[idx]);
			tmp += dp[i][k];
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}
