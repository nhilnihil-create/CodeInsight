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

	ll res = 1;
	for (int i = 1; i <= N; ++i) {
		ll tmp = 0;
		if (T[i] == T[i - 1]) {
			if (A[i] == A[i + 1]) { tmp = min(T[i], A[i]); }
			else if (T[i] >= A[i]) { tmp = 1; }
		} else {
			if ((A[i] == A[i + 1] && A[i] >= T[i]) || (A[i] != A[i + 1] && A[i] == T[i])) {
				tmp = 1;
			}
		}
		res = (res * tmp) % MOD;
	}

	cout << res % MOD << endl;

	return 0;
}
