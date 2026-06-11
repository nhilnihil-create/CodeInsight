#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
ll x[100000], y[100000];
ll sumX[100000], sumY[100000];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < m; i++) cin >> y[i];
	sumX[n - 1] = x[n - 1];
	for (int i = n - 2; i >= 0; i--) sumX[i] = (sumX[i + 1] + x[i]) % MOD;
	sumY[m - 1] = y[m - 1];
	for (int i = m - 2; i >= 0; i--) sumY[i] = (sumY[i + 1] + y[i]) % MOD;
	ll X = 0, Y = 0;
	for (int i = 0; i < n; i++) {
		ll t = sumX[i];
		(t += MOD - ((n - i)*x[i]) % MOD) %= MOD;
		(X += t) %= MOD;
	}
	for (int i = 0; i < m; i++) {
		ll t = sumY[i];
		(t += MOD - ((m - i)*y[i]) % MOD) %= MOD;
		(Y += t) %= MOD;
	}
	cout << (X*Y) % MOD << endl;
}