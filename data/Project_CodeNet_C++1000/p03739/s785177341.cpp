#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	// +-+-...の場合
	ll res1 = 0;
	ll total = 0;
	for (int i = 0; i < n; ++i) {
		if (i & 1) { // 和が負
			if (total + a[i] < 0) {
				total += a[i];
			}
			else {
				res1 += abs(total + a[i] + 1);
				total = -1;
			}
		}
		else {
			if (total + a[i] > 0) {
				total += a[i];
			}
			else {
				res1 += abs(total + a[i] - 1);
				total = 1;
			}
		}
		// cout << res1 << " " << total << endl;
	}
	// -+-+....の場合
	ll res2 = 0;
	total = 0;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) { // 和が負
			if (total + a[i] < 0) {
				total += a[i];
			}
			else {
				res2 += abs(total + a[i] + 1);
				total = -1;
			}
		}
		else {
			if (total + a[i] > 0) {
				total += a[i];
			}
			else {
				res2 += abs(total + a[i] - 1);
				total = 1;
			}
		}
		// cout << res2 << " " << total << endl;
	}
	cout << min(res1, res2) << endl;
	return 0;
}