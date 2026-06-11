#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n, m; cin >> n >> m;
	int64_t a[n]; for(int i = 0; i < n; ++i) cin >> a[i];
	int64_t imos[2 * m + 1] = {};
	vector<int> v[m + 1];
	for(int i = 1; i < n; ++i) {
		v[a[i]].push_back(i);
		if(a[i - 1] < a[i]) {
			++imos[a[i - 1] + 2];
			--imos[a[i] + 1];
		} else {
			++imos[a[i - 1] + 2];
			--imos[a[i] + 1 + m];
		}
	}
	for(int i = 1; i <= 2 * m; ++i) {
		imos[i] += imos[i - 1];
	}
	int64_t ans[m + 1] = {};
	for(int i = 1; i < n; ++i) {
		if(a[i - 1] < a[i]) {
			ans[1] += a[i] - a[i - 1];
		} else {
			ans[1] += a[i];			
		}
	}
	for(int i = 2; i <= m; ++i) {
		ans[i] = ans[i - 1];
		ans[i] -= imos[i] + imos[i + m];
		for(int j : v[i - 1]) {
			if(a[j - 1] < a[j]) {
				ans[i] += a[j] - a[j - 1] - 1;
			} else {
				ans[i] += (a[j] + m) - a[j - 1] - 1;
			}
		}
	}
	int64_t anss = 1e18;
	for(int i = 1; i <= m; ++i) {
		anss = min(anss, ans[i]);
	}
	cout << anss << '\n';
	return 0;
}