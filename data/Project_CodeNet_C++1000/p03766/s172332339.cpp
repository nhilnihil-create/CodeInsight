#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

ll solve() {
	ll N;
	cin >> N;
	const ll MOD = 1e9 + 7;
	auto Add = [&](ll& x, ll y) { x = (x + y % MOD) % MOD; };
	auto Mul = [&](ll& x, ll y) { x = (x * y % MOD) % MOD; };
	vector<ll> dp(N + 1), c(N + 1);
	dp[0] = 1, c[0] = 1;
	for (int i = 1; i <= N; i++) {
		Add(dp[i], dp[i - 1]);
		if (i >= 3) Add(dp[i], c[i - 3]);
		Add(c[i], c[i - 1]);
		Add(c[i], dp[i]);
	}
	ll ans = 0;
	for (int i = 0; i <= N - 2; i++) {
		ll x = dp[i];
		Mul(x, N - 1);
		Mul(x, N - 1);
		Add(ans, x);
	}
	{
		ll x = dp[N];
		Add(ans, x);
	}
	{
		ll x = dp[N - 1];
		Mul(x, N - 1);
		Add(ans, x);
	}
	for (int i = 0; i <= N - 2; i++) {
		ll x = dp[i];
		Mul(x, i + 1);
		Add(ans, x);
	}
	return ans;
}

int main() {
	auto ans = solve();
	cout << ans << "\n";
	return 0;
}