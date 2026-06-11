#include <algorithm>
#include <iostream>
using namespace std;
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using ll = long long;
int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	rep(i, n) cin >> a[i];
	int p = a[0];
	rep(i, n) p = __gcd(p, a[i]);
	bool ch = 0;
	rep(i, n) {
		if (k > a[i]) continue;
		if ((a[i] - k) % p == 0) ch = 1;
	}
	cout << (ch ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	return 0;
}