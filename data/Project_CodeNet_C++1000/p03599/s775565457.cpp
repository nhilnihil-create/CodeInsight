#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	vector<int> dp(f + 1, -1);
	dp[0] = 0;

	for (int i = 0; i < f; i++) {
		if (dp[i] == -1) {
			continue;
		}

		int sugar = dp[i];
		int water = i - dp[i];

		int next1 = i + 100 * a;
		int next2 = i + 100 * b;
		int next3 = i + c;
		int next4 = i + d;

		if (next1 <= f) {
			dp[next1] = max(dp[next1], dp[i]);
		}
		if (next2 <= f) {
			dp[next2] = max(dp[next2], dp[i]);
		}
		if (next3 <= f && (sugar + c) <= water * e / 100) {
			dp[next3] = max(dp[next3], dp[i] + c);
		}
		if (next4 <= f && (sugar + d) <= water * e / 100) {
			dp[next4] = max(dp[next4], dp[i] + d);
		}
	}

	pair<int, int> ans = make_pair(100 * a, 0);
	for (int i = 0; i < dp.size(); i++) {
		if (dp[i] == -1) {
			continue;
		}

		int sugar = dp[i];
		int water = i - dp[i];
		if (dp[i] * ans.first > ans.second * i) {
			ans = make_pair(i, dp[i]);
		}
	}

	cout << ans.first << " " << ans.second << endl;

	return 0;
}
