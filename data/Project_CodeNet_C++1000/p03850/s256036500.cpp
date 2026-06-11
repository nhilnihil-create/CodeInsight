#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100009]; long long dp[100009][7]; bool vis[100009][7]; string s[100009];
long long solve(int pos, int depth) {
	if (pos == n) return 0;
	if (vis[pos][depth]) return dp[pos][depth];
	long long ret = -1LL << 61;
	if (s[pos] == "+") {
		ret = solve(pos + 1, depth) + a[pos] * (depth % 2 ? -1 : 1);
		if (depth > 0) ret = max(ret, solve(pos + 1, depth - 1) + a[pos] * (depth % 2 ? -1 : 1));
	}
	else {
		ret = solve(pos + 1, depth) + a[pos] * (depth % 2 ? 1 : -1);
		if (depth > 0) ret = max(ret, solve(pos + 1, depth - 1) + a[pos] * (depth % 2 ? 1 : -1));
		if (depth < 6) ret = max(ret, solve(pos + 1, depth + 1) + a[pos] * (depth % 2 ? 1 : -1));
	}
	vis[pos][depth] = true;
	dp[pos][depth] = ret;
	return ret;
}
int main() {
	cin >> n;
	s[0] = "+"; cin >> a[0];
	for (int i = 1; i < n; i++) cin >> s[i] >> a[i];
	long long ret = solve(0, 0);
	cout << ret << endl;
	return 0;
}