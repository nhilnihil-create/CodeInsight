#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int x[N], d[N], ans[N];
int main() {
	int n, l, t;
	scanf("%d%d%d", &n, &l, &t);
	vector<int> L, R;
	for (int i = 0; i < n; ++ i) {
		scanf("%d%d", &x[i], &d[i]);
		(d[i] == 1 ? R : L).push_back(x[i]);
		(d[i] == 1 ? R : L).push_back(x[i] - l);
		(d[i] == 1 ? R : L).push_back(x[i] + l);
	}
	sort(L.begin(), L.end());
	sort(R.begin(), R.end());
	if (L.empty()) {
		for (int i = 0; i < n; ++ i) printf("%lld ", 1LL * (x[i] + t) % l); puts("");
		return 0;
	}
	if (R.empty()) {
		for (int i = 0; i < n; ++ i) printf("%lld ", (1LL * (x[i] - t) % l + l) % l); puts("");
		return 0;
	}
	int base = (2 * t) / l;
	for (int i = 0; i < n; ++ i) {
		if (d[i] == 1) {
			int rt = 2 * t - base * l;
			int cnt = upper_bound(L.begin(), L.end(), x[i] + rt) - lower_bound(L.begin(), L.end(), x[i]);
			cnt += 1LL * base * L.size() / 3 % n;
			ans[(i + cnt) % n] = (x[i] + t) % l;
		}
		else {
			int rt = 2 * t - base * l;
			int cnt = upper_bound(R.begin(), R.end(), x[i]) - lower_bound(R.begin(), R.end(), x[i] - rt);
			cnt += 1LL * base * R.size() / 3 % n;
			ans[((i - cnt) % n + n) % n] = ((x[i] - t) % l + l) % l;
		}
	}
	for (int i = 0; i < n; ++ i) printf("%d ", ans[i]); puts("");
}
