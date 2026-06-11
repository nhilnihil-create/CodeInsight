#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	const ll MOD = 1e9 + 7;
	int N;
	cin >> N;
	vector<ll> T(N + 2, 0);
	vector<ll> A(N + 2, 0);
	for (int i = 1; i <= N; ++i) { cin >> T[i]; }
	for (int i = 1; i <= N; ++i) { cin >> A[i]; }

	vector<ll> d(N + 2, 0);
	for (int i = 1; i <= N; ++i) {
		if (T[i] == T[i - 1]) {
			d[i] = T[i];
		} else {
			d[i] = -T[i];
		}
	}
	bool exist = true;
	for (int i = N; i >= 1; --i) {
		if (A[i] == A[i + 1]) {
			if (d[i] < 0) {
				if (abs(d[i]) > A[i]) { exist = false; }
			} else {
				d[i] = min(d[i], A[i]);
			}
		} else {
			if (d[i] < 0) {
				if (abs(d[i]) != A[i]) { exist = false; }
			} else {
				if (d[i] < A[i]) { exist = false; }
				else { d[i] = -A[i]; }
			}
		}
	}

	if (!exist) {
		cout << 0 << endl;
	} else {
		ll res = 1;
		for (int i = 1; i <= N; ++i) {
			if (d[i] > 0) {
				res = (res * d[i]) % MOD;
			}
		}
		cout << res % MOD << endl;
	}

	return 0;
}
