#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const LL MOD = 1000000007LL;
LL x[100000];
LL y[100000];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		(x[i] += MOD) %= MOD;
	}
	for (int i = 0; i < m; i++) {
		cin >> y[i];
		(y[i] += MOD) %= MOD;
	}
	LL sum_x = 0;
	for (int i = 0; i < n; i++) {
		LL add = (2 * i - (n - 1) + MOD) % MOD;
		(add *= x[i]) %= MOD;
		(sum_x += add) %= MOD;
	}
	LL sum_y= 0;
	for (int i = 0; i < m; i++) {
		LL add = (2 * i - (m - 1) + MOD) % MOD;
		(add *= y[i]) %= MOD;
		(sum_y += add) %= MOD;
	}
	cout << (sum_x*sum_y) % MOD << endl;
}