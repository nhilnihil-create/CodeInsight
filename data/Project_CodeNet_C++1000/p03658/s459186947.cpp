#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
#define all(x) x.begin(), x.end()

signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	reverse(all(a));
	int ans = 0;
	rep(i, k) ans += a[i];
	cout << ans << endl;
}
