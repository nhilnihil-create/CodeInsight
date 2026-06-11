
// D - No Need

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int N, K;
int a[5000];
bool dp[5001][5001]; // dp[i][j]: i個目までのaで和をjにできるか

// 不必要ならok
bool is_ok(ll k) {
	if (a[k] >= K) return false;

	//cout << "k = " << k << endl; // **** debug ****
	for (int i=0; i<5001; i++) {
		for (int j=0; j<5001; j++) {
			dp[i][j] = false;
		}
	}

	dp[0][0] = true;

	for (int i=0; i<N; i++) {
		for (int j=0; j<=5000; j++) {
			dp[i+1][j] = dp[i+1][j] || dp[i][j];

			if (i == k) continue;
			if (dp[i][j] == false) continue;

			if (j + a[i] <= 5000) dp[i+1][j + a[i]] = true;
		}
	}

	bool result = true;
	for (int j=K-a[k]; j<K; j++) {
		if (dp[N][j] == true) result = false;
	}

	// **** debug ****
	/*
	for (int i=0; i<=N; i++) {
		for (int j=0; j<=30; j++) {
			cout << dp[i][j];
		}
		cout << endl;
	}
	*/

	//cout << "result: " << result << endl; // **** debug ****

	return result;
}

// 不必要ならok
ll find_max_ok(ll lower, ll upper) {
	if (!is_ok(lower)) return -1; // 存在しない

	ll ok = lower;
	ll ng = upper;

	while(ng - ok > 1) {
		ll trying = (ng + ok) / 2;

		if (is_ok(trying)) {
			ok = trying;
		} else {
			ng = trying;
		}
	}

	return ok;
}

int main(){
	cin >> N >> K;

	for (int i=0; i<N; i++) {
		cin >> a[i];
	}

	sort(a, a+N);

	int ans = find_max_ok(0, N) + 1;

	cout << ans << endl;

	return 0;
}