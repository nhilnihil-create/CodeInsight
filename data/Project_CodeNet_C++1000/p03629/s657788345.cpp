#include <bits/stdc++.h>
#define ls (o << 1)
#define rs (o << 1 | 1)
#define mid ((L + R) >> 1)
using namespace std;
typedef long long LL;
const int N = 200500;
const int mod = 1e9 + 7;
char s[N];
int suf[N][26], dp[N];
int n;
int main() {
#ifdef TEST
	freopen("input.txt", "r", stdin);
#endif
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < 26; ++i) {
		suf[n][i] = n;
	}
	for (int i = n - 1; i >= 0; --i) {
		dp[i] = n + 5;
		for (int j = 0; j < 26; ++j) {
			suf[i][j] = suf[i + 1][j];
			dp[i] = min(dp[i], dp[suf[i][j]] + 1);
		}
		suf[i][s[i] - 'a'] = i;
	}
	int now = 0;
	while (*max_element(suf[now], suf[now] + 26) != n) {
		int nxt = suf[now][0];
		for (int i = 1; i < 26; ++i) {
			if (dp[suf[now][i]] < dp[nxt]) {
				nxt = suf[now][i];
			}
		}
		printf("%c", s[nxt]);
		now = nxt + 1;
	}
	printf("%c", max_element(suf[now], suf[now] + 26) - suf[now] + 'a');
	return 0;
}
