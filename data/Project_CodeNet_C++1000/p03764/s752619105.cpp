#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 7;

int x[N], y[N];

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for(int i = 1; i <= m; i++) {
		cin >> y[i];
	}
	int ans = 0, p = 0, q = 0;
	for(int i = 1; i < n; i++) {
		p += (i * (n - i) % mod) * (x[i + 1] - x[i]) % mod;
		p %= mod;
	}
	for(int i = 1; i < m; i++) {
		q += (y[i + 1] - y[i]) * (i * (m - i) % mod) % mod;
		q %= mod;
	}
	cout << p * q % mod << endl;
}