#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n, k; cin >> n >> k;
	int64_t a[n], b[n]; for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];
	int64_t ans = 0;
	for(int i = 0; i < n; ++i) {
		if((a[i] | k) == k) {
			ans += b[i];
		}
	}
	for(int64_t i = 0; i < 40; ++i) {
		if((1ll << i) > k) break;
		if(not (k >> i & 1)) continue;
		int64_t mask = (k & (~(1ll << i))) | ((1ll << i) - 1);
		int64_t sum = 0;
		for(int j = 0; j < n; ++j) {
			if((a[j] | mask) == mask) {
				sum += b[j];
			}
		}
		ans = max(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}