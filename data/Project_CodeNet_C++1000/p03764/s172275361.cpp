#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n, m;
	cin >> n >> m;
	int64_t x[n], y[m], mod = 1e9 + 7;
	for (auto &i : x) {
		cin >> i;
	}
	for (auto &i : y) {
		cin >> i;
	}
	int64_t a = 0, b = 0;
	for (int64_t i = 0; i < n; i++) {
		(a += x[i] * (i - (n - i - 1))) %= mod;
	}
	for (int64_t i = 0; i < m; i++) {
		(b += y[i] * (i - (m - i - 1))) %= mod;
	}
	cout << a * b % mod << endl;
	return 0;
}