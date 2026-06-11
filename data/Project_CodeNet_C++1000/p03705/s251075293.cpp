#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	if (a > b) {
		cout << 0 << endl;
		return 0;
	}
	if (n == 1 && a != b) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = (b - a) * (n - 2) + 1;
	cout << ans << endl;
	return 0;
}