#include <bits/stdc++.h>
using namespace std;

int dp[200010];
int last[200010], CCC[200010];
int nxt[26];

int main () {
	string s; cin >> s;
	int n = s.size();
	for (int i = 0; i < 26; i++) {
		nxt[i] = n;
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[n] = 1, dp[n + 1] = 0;
	for (int i = n - 1; i >= 0; i--) {
		nxt[s[i] - 'a'] = i;
		for (int j = 0; j < 26; j++) {
			if (dp[i] > dp[nxt[j] + 1] + 1) {
				dp[i] = dp[nxt[j] + 1] + 1;
				last[i] = nxt[j] + 1, CCC[i] = j;
			}
		}
	}
	int now = 0;
	while (now < n) {
		printf("%c", char(CCC[now] + 'a'));
		now = last[now];
	}
	printf("\n");
	return 0;
}
