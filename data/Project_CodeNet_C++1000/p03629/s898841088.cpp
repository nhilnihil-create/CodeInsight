#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
LL MOD = 1000000007LL;
int pos[200000][26];
int dp[200001][26];
int main() {
	string A;
	cin >> A;
	int N = A.size();
	fill((int*)pos, (int*)(pos + N), -1);
	for (int i = N - 1; i >= 0; i--) {
		if (i + 1 < N) {
			for (int j = 0; j < 26; j++) pos[i][j] = pos[i + 1][j];
		}
		pos[i][A[i] - 'a'] = i;
	}
	fill((int*)dp, (int*)(dp + N + 1), 1 << 30);
	dp[N][0] = 1;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			if (pos[i][j] == -1) {
				dp[i][j] = 1;
				continue;
			}
			int p = pos[i][j] + 1;
			for (int k = 0; k < 26; k++) {
				if (dp[p][k] == 1 << 30) continue;
				dp[i][j] = min(dp[i][j], dp[p][k] + 1);
			}
		}
	}
	string ans = "";
	int p = 0;
	while (1) {
		int idx = 0;
		for (int i = 0; i < 26; i++) {
			if (dp[p][i] < dp[p][idx]) idx = i;
		}
		ans.push_back('a' + idx);
		if (dp[p][idx] == 1) break;
		p = pos[p][idx] + 1;
	}
	cout << ans << endl;
}