#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
int main() {
	int n;
	cin >> n;
	ll a[n];
	rep(i, n) cin >> a[i];
	ll m = 1, ans = a[0] - 1;
	repl(i, 1, n) {
		if (a[i] == m + 1)
			m++;
		else
			ans += (a[i] - 1) / (m + 1);
	}
	cout << ans << endl;
	return 0;
}