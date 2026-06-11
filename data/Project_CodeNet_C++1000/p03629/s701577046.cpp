#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>

const int MAXN = 2e5 + 10, MAXS = 26;

int len;
int dp[MAXN], ch[MAXN][MAXS], nxt[MAXS];
char s[MAXN];

int main() {
	s[0] = 'a';
	scanf(" %s", s + 1), len = strlen(s + 1);
	for (int i = 0; i < MAXS; ++i) nxt[i] = len + 1;
	for (int i = len; ~i; --i) {
		int v = s[i] - 'a'; dp[i] = 23333333;
		std::copy(nxt, nxt + MAXS, ch[i]);
		for (int j = 0; j < MAXS; ++j) dp[i] = std::min(dp[i], dp[nxt[j]] + 1);
		nxt[v] = i;
	}
	int u = 0;
	for (; u <= len;) {
		for (int k = 0; k < MAXS; ++k) if (dp[u] == dp[ch[u][k]] + 1) { putchar(k + 'a'), u = ch[u][k]; break; }
	}
	puts("");
	return 0;
}