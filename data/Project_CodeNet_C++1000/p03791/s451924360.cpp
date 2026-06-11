#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	constexpr Int MOD = 1e9 + 7;
	int N;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; ++i) { cin >> x[i]; }

	Int ans = 1;
	Int ready = 0;
	for (int i = 0; i < N; ++i) {
		++ready;
		if (x[i] >= 2 * ready - 1) { continue; }
		(ans *= ready) %= MOD;
		--ready;
	}
	for (Int i = 1; i <= ready; ++i) {
		(ans *= i) %= MOD;
	}
	cout << ans % MOD << "\n";

	return 0;
}
