#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

const int mod = 1000000007;

int main() {
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;

	vector<long long> dp(n, 0);
	dp[0] = 1;

	if (s1[0] == s2[0]) {
		dp[0] = 3;
	} else {
		dp[0] = 3 * 2;
	}

	for (int i = 1; i < n; i++) {
		if (s1[i] == s1[i-1]) {
			dp[i] = dp[i-1];
		} else if (s1[i] == s2[i]) {
			if (s1[i-1] == s2[i-1]) {
				dp[i] = dp[i-1] * 2 % mod;
			} else {
				dp[i] = dp[i-1];
			}
		} else if (s1[i-1] == s2[i-1]) {
			dp[i] = dp[i-1] * 2 % mod;
		} else {
			dp[i] = dp[i-1] * 3 % mod;
		}
	}
	cout << dp.back() << endl;
	return 0;
}
