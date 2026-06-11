#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int N = 1e6 + 7;

int add(int a, int b) {
	return (a + b) % MOD;
}

int mul(int a, int b) {
	return (a * b) % MOD;
}

int dp[N];
int ps[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	dp[0] = 1;
	ps[0] = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (i - 3 >= 0) dp[i] = add(dp[i], ps[i - 3]);
		ps[i] = add(ps[i - 1], dp[i]);
	}
	for (int i = 0; i < n; i++) {
		int l = (n - i);
		int r = n;
		l = max(l, (int)2);
		if (l <= r) {
			ans = add(ans, mul(dp[i], r - l + 1));
		}
	}
	for (int i = 0; i <= n; i++) {
		if (i + 2 <= n) {
			int v = mul(n - 1, n - 1);
			v = mul(v, dp[i]);
			ans = add(ans, v);
		} else if (i == n) {
			ans = add(ans, dp[i]);
		}
	}
	cout << ans << endl;
}
