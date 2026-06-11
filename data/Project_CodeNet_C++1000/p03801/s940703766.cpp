#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n]; for(int i = 0; i < n; ++i) cin >> a[i];
	// {num, idx}
	pair<int64_t, int64_t> p[n + 1];
	for(int i = 0; i < n; ++i) {
		p[i] = {a[i], i};
	}
	p[n] = {0, 0};
	sort(p, p + n + 1);
	reverse(p, p + n + 1);
	int64_t ans[n] = {};
	for(int64_t mini = 1e9, i = 0; i < n; ++i) {
		mini = min(mini, p[i].second);
		if(p[i].first == p[i + 1].first) continue;
		ans[mini] += (i + 1) * (p[i].first - p[i + 1].first);
	}
	for(int i = 0; i < n; ++i) {
		cout << ans[i] << '\n';
	}
	return 0;
}

