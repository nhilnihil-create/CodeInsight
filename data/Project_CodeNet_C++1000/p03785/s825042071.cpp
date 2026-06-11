#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, c, k;
	cin >> n >> c >> k;
	vector<int> t(n);
	map<int, int> mp;
	rep(i, n) cin >> t[i];
	sort(all(t));
	int ans = 1;
	int cnt = 0;
	int lim = t[0] + k;
	rep(i, n) {
		mp[t[i]]++;
	}
	rep(i, n) {
		cnt++;
		if (cnt > c) {
			ans++;
			cnt = 1;
			lim = t[i] + k;
		} else if (lim < t[i]) {
			ans++;
			cnt = 1;
			lim = t[i] + k;
		}
	}
	
	cout << ans << endl;
	return 0;
}