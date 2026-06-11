#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;

int main() {
	int N, K; cin >> N >> K;
	vector<ll> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }
	sort(a.begin(), a.end());

	int low = -1, high = N;
	int res;
	while (high - low != 1) {
		int mid = (high + low) / 2;

		vector<bool> dp(K, false);
		dp[0] = true;

		for (int i = 0; i < N; ++i) {
			if (i == mid) continue;
			if (a[i] >= K) continue;

			vector<bool> next(K, false);
			for (int j = 0; j < K; ++j) {
				next[j] = (next[j] | dp[j]);
				if (j - a[i] >= 0) {
					next[j] = (next[j] | dp[j - a[i]]);
				}
			}
			dp = next;
		}

		bool is_need = false;
		for (int sum = max(0LL, (ll)K - a[mid]); sum < K; ++sum) {
			if (dp[sum]) {
				is_need = true;
				break;
			}
		}

		if (is_need) { high = mid; }
		else { low = mid; }
	}

	cout << low + 1 << endl;
	return 0;
}
