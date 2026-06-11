#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (auto &it : a) {
		cin >> it;
	}
	vector<int> cur = a;
	int ans = 1e18;
	for (int shift = 0; shift < n; shift++) {
		int sum = x * shift;
		for (int i = 0; i < n; i++) {
			cur[i] = min(cur[i], a[(i - shift + n) % n]);
			sum += cur[i];
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';
}