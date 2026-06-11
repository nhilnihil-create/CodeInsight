#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n, c, k;
	cin >> n >> c >> k;
	vector<int> t(n);
	rep(i, n) cin >> t[i];
	sort(t.begin(), t.end());
	int now = t[0], cnt = 1;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (t[i] <= now + k && cnt < c) cnt++;
		else {
			ans++;
			now = t[i];
			cnt = 1;
		}
	}
	cout << ans << endl;
	return 0;
}