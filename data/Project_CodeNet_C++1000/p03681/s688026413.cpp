
// C - Reconciled?

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
const ll MOD = 1e9 + 7;

int main() {
	ll N, M;
	cin >> N >> M;

	if (abs(N - M) > 1) {
		cout << 0 << endl;
		return 0;
	}

	ll ans = 1;

	for (int i=1; i<=N; i++) {
		ans = (ans * i) % MOD;
	}

	for (int i=1; i<=M; i++) {
		ans = (ans * i) % MOD;
	}

	if (N == M) ans = (ans * 2) % MOD;

	cout << ans << endl;

	return 0;
}