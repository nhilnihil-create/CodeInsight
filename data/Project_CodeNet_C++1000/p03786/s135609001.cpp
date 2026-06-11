#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	vector<ll> a(n);
	rep(i, 0, n) cin >> a[i];
	sort(a.begin(), a.end());

	ll s = 0;
	int t = 0;
	rep(i, 0, n - 1) {
		s += a[i];
		if (s * 2 < a[i + 1]) t = i + 1;
	}
	cout << n - t << endl;
	return 0;
}
