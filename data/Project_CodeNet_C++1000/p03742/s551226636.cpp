#include <bits/stdc++.h>
#define ls (o << 1)
#define rs (o << 1 | 1)
#define mid ((L + R) >> 1)
using namespace std;
typedef long long LL;
const int N = 25;
int dp[N][N];
int dfs(int a, int b) {
	if (~dp[a][b]) return dp[a][b];
	vector<int> nxt;
	for (int i = 1; i + i <= a; ++i) {
		nxt.push_back(dfs(a - i - i, b + i));
	}
	for (int i = 1; i + i <= b; ++i) {
		nxt.push_back(dfs(a + i, b - i - i));
	}
	sort(nxt.begin(), nxt.end());
	nxt.resize(unique(nxt.begin(), nxt.end()) - nxt.begin());
	dp[a][b] = 0;
	for (auto &i : nxt) {
		if (i == dp[a][b]) {
			dp[a][b]++;
		}
	}
	return dp[a][b];
}
int main() {
#ifdef TEST
	freopen("input.txt", "r", stdin);
#endif
	// memset(dp, -1, sizeof(dp));
	// for (int i = 0; i < 11; ++i) {
	// 	for (int j = 0; j < 11; ++j) {
	// 		printf("%3d", dfs(i, j));
	// 	}
	// 	printf("\n");
	// }
	LL a, b;
	cin >> a >> b;
	if (abs(a - b) <= 1) {
		puts("Brown");
	} else {
		puts("Alice");
	}
	return 0;
}