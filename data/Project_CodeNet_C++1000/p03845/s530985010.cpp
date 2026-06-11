#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

signed main() {
	int n;
	cin >> n;
	vector<int> t(n);
	rep(i, n) cin>>t[i];
	int m; cin >> m;
	vector<int> p(m);
	vector<int> x(m);
	rep(i, m) cin >> p[i] >> x[i];
	
	int max = 0;
	rep(i, n) max += t[i];
	rep(i, m) {
		int ans = max - t[p[i]-1] + x[i];
		cout << ans << endl;
	}
	return 0;
}
