#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {
	ll n, c, k; cin >> n >> c >> k;
	vector<ll>t(n); for (auto&& x : t)cin >> x;
	sort(t.begin(), t.end());

	ll cnt = 1, time = t[0] + k, ans = 1;
	for (int i = 1; i < n; i++) {
		if (t[i] <= time && cnt < c)cnt++;
		else time = t[i] + k, cnt = 1, ans++;
	}
	cout << ans << endl;

	return 0;
}