#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 200000 + 7, C = 31;

int n;
char s[N];
int nxt[N][C], dp[N], frm[N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int j = 0; j < 26; ++j)
		nxt[n + 1][j] = n + 1;
		
	dp[n + 1] = 1;
	for (int i = n; i; --i) {
		dp[i] = 1 << 29;
		for (int j = 25; j >= 0; --j) {
			nxt[i][j] = s[i] == 'a' + j ? i : nxt[i + 1][j];
			if (dp[nxt[i][j] + 1] < dp[i])
				dp[i] = dp[nxt[i][j] + 1],
				frm[i] = j;
		}
		++dp[i];
	}
	
	for (int i = 1, j; i <= n; i = nxt[i][j] + 1)
		for (j = 0; j < 26; ++j)
			if (dp[i] == dp[nxt[i][j] + 1] + 1) {
				printf("%c", 'a' + j);
				break;
			}

	return 0;
}
