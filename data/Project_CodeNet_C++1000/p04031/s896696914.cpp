#include <bits/stdc++.h>
#define sqr(x) (x)*(x)
#define int long long
using namespace std;

signed main() {
#ifdef _DEBUG
	freopen("_in" , "r", stdin );
	freopen("_out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	int n, s = 0; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
	if(s > 0) s += n / 2;
	if(s < 0) s -= n / 2;
	s /= n;
	int ans = 0;
	for (int i = 0; i < n; i++) ans += sqr(s - a[i]);
	cout << ans << '\n';
}
