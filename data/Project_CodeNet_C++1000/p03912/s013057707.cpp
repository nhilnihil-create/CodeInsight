#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int ans = 0;
	vector<int> x(n);
	vector<int> cnt(100001);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		cnt[x[i]]++;
	}

	vector<int> cnt2(m);
	vector<int> p(m);
	for (int i = 0; i <= 100000; i++) {
		cnt2[i % m] += cnt[i];
		p[i % m] += cnt[i] / 2;
	}

	for (int i = 0; i < m; i++) {
		int j = (m - i) % m;
		if (i != j) {
			if (cnt2[i] > cnt2[j]) {
				ans += cnt2[j];
				ans += min((cnt2[i] - cnt2[j]) / 2, p[i]);
			} else {
				ans += cnt2[i];
				ans += min((cnt2[j] - cnt2[i]) / 2, p[j]);
			}
			cnt2[i] = 0;
			cnt2[j] = 0;
			p[i] = 0;
			p[j] = 0;
		} else {
			ans += cnt2[i] / 2;
			cnt2[i] = 0;
		}
	}
	cout << ans << endl;
}