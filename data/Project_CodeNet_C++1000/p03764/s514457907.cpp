#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<int, P> E;
const LL MOD = 1000000007LL;
LL x[100000];
LL y[100000];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> x[i], (x[i] += MOD) %= MOD;
	for (int i = 0; i < m; i++) cin >> y[i], (y[i] += MOD) %= MOD;
	LL sumX = 0;
	for (int i = 0; i < n; i++) {
		(sumX += x[i] * i) %= MOD;
		LL sub = (x[i] * (n - 1 - i)) % MOD;
		sumX = (sumX - sub + MOD) % MOD;
	}
	LL sumY = 0;
	for (int i = 0; i < m; i++) {
		(sumY += y[i] * i) %= MOD;
		LL sub = (y[i] * (m - 1 - i)) % MOD;
		sumY = (sumY - sub + MOD) % MOD;
	}
	cout << (sumX*sumY) % MOD << endl;
}