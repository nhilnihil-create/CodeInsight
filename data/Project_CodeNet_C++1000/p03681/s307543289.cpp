#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;
const int MAX_NUM = 999999999;
void solve() {
	int64 n, m; cin >> n >> m;
	int64 ans = 1 + (n == m);
	if (max(n, m) - min(n, m) > 1) {
		cout << 0 << endl;
		return;
	}
	for (int i = n; i >= 1; --i) {
		ans = (ans * i) % MOD;
	}
	for (int i = m; i >= 1; --i) {
		ans = (ans * i) % MOD;
	}
	cout << ans << endl;
	return;
}
int main() {
	solve();
	return 0;
}