#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }

	bool ok = true;
	sort(a.begin(), a.end());
	if (a.back() - a[0] > 1) { ok = false; }

	if (a[0] == a.back()) {
		ok = ok && (N / 2 >= a[0] || N == a[0] + 1);
	} else {
		int cnt_min = 0, cnt_max = 0;
		for (auto v : a) {
			if (v == a[0]) { ++cnt_min; }
			if (v == a.back()) { ++cnt_max; }
		}
		if (cnt_max < 2 || a.back() <= cnt_min) { ok = false; }
		ok = ok && (cnt_max / 2 >= a.back() - cnt_min);
	}
	cout << (ok ? "Yes" : "No") << endl;

	return 0;
}
