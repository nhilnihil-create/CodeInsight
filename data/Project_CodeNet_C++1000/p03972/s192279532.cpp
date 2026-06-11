#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t w, h; cin >> w >> h;
	vector<pair<int64_t, int>> v(w + h);
	for(int i = 0; i < w + h; ++i) {
		int64_t a; cin >> a;
		v[i] = {a, i < w};
	}
	sort(v.begin(), v.end());
	int64_t wcnt = w + 1, hcnt = h + 1;
	int64_t ans = 0;
	for(auto e : v) {
		int64_t cost, flg;
		tie(cost, flg) = e;
		if(flg) {
			ans += hcnt * cost;
			--wcnt;
		} else {
			ans += wcnt * cost;
			--hcnt;
		}
	}
	cout << ans << '\n';
	return 0;
}
