#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll a[100010], sum[100010];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cin >> a[0];
	vector<int> minus;
	for (int i = 1; i < n; i++) {
		char op;
		cin >> op >> a[i];
		if (op == '-') minus.push_back(i);
	}

	for (int i = n - 2; i >= 0; i--) {
		sum[i] = sum[i + 1] + a[i + 1];
	}

	ll ans = 0, hoge = 0;
	if (minus.empty()) {
		for (int i = 0; i < n; i++) {
			ans += a[i];
		}
	} else {
		for (int i = 0; i < minus.front(); i++) hoge += a[i];
		for (int i = 0; i < minus.size(); i++) {
			hoge -= a[minus[i]];
			if (i + 1 == minus.size()) {
				hoge += sum[minus[i]];
				ans = max(ans, hoge);
			} else {
				ll tmp = sum[minus[i]] - sum[minus[i + 1] - 1];
				ans = max(ans, hoge + sum[minus[i + 1] - 1] - tmp);
				hoge += tmp;
			}
		}
	}

	cout << ans << endl;
	return 0;
}