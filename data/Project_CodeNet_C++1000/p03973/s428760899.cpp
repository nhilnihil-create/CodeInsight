#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<Int> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }

	Int ans = a[0] - 1;
	Int max_a = 1;
	for (int i = 1; i < N; ++i) {
		if (a[i] - max_a < 2) {
			max_a = max(max_a, a[i]);
			continue;
		}
		Int P = max_a + 1;
		ans += a[i] / P + (a[i] % P ? 0 : -1);
		a[i] = 1;
	}
	cout << ans << endl;

	return 0;
}
