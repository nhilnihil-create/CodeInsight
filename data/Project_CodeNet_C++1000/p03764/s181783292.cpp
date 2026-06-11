#include <bits/stdc++.h>

using ll = long long;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

int n, m;
ll x[100005], y[100005];
ll sumX[100005], sumY[100005];
int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
		std::cin >> x[i];
	for (int i = 0; i < m; i++)
		std::cin >> y[i];

	sumX[n - 1] = x[n - 1];
	for (int i = n - 2; i >= 0; i--)
		sumX[i] = (sumX[i + 1] + x[i]) % mod;

	sumY[m - 1] = y[m - 1];
	for (int i = m - 2; i >= 0; i--)
		sumY[i] = (sumY[i + 1] + y[i]) % mod;

	ll X = 0, Y = 0;
	for (int i = 0; i < n; i++) {
		ll t = sumX[i];
		(t += mod - ((n - i)*x[i]) % mod) %= mod;
		(X += t) %= mod;
	}
	for (int i = 0; i < m; i++) {
		ll t = sumY[i];
		(t += mod - ((m - i)*y[i]) % mod) %= mod;
		(Y += t) %= mod;
	}
	std::cout << (X*Y) % mod << std::endl;
}
