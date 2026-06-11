// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;

const int maxn = 500005, Inf = (1 << 30);
char s[maxn];
int n, f[maxn], cnt[maxn][26];

void dfs(int k, int len)
{
	if(len == 1) {
		for(int i = 0; i < 26; ++i)
			if(cnt[k][i] == n + 1) {
				printf("%c", 'a' + i); return;
			}
	}
	for(int i = 0; i < 26; ++i)
		if(f[cnt[k][i]] == len) {
			printf("%c", 'a' + i); dfs(cnt[k][i] + 1, len - 1);
			break;
		}
}

inline void chkmin(int &a, int b)
{
	if(a > b) a = b;
}

int main()
{
	scanf("%s", s + 1); n = strlen(s + 1);

	for(int i = 0; i < 26; ++i) cnt[n + 1][i] = n + 1;

	f[n + 1] = 1;
	for(int i = n; i >= 1; --i) {
		memcpy(cnt[i], cnt[i + 1], sizeof(cnt[i]));
		f[i] = Inf;
		for(int j = 0; j < 26; ++j) chkmin(f[i], f[cnt[i][j]] + 1);
		cnt[i][s[i] - 'a'] = i;
	}

	for(int i = 0; i < 26; ++i)
		if(cnt[1][i] == n + 1) printf("%c", 'a' + i), exit(0);
	int ans = Inf;
	for(int i = 0; i < 26; ++i) chkmin(ans, f[cnt[1][i]]);
    dfs(1, ans);
	return 0;
}
