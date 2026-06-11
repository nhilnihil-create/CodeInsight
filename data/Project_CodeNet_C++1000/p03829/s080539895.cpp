// arc067_b.cc
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	vector<ll> x(n);
	for (auto &e : x)
		cin >> e;

	vector<long long> dp(n, LLONG_MAX);
	dp[0] = 0;

	for (int i = 1; i < n; i++) {
		dp[i] = min(dp[i-1] + ((x[i] - x[i-1]) * a), dp[i-1] + b);
	}

	cout << dp.back();
}