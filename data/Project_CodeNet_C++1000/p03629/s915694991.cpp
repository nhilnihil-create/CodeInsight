#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
const int maxn = 200005;
int f[maxn], nxt[maxn][26], last[26], n;
char s[maxn];
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	rep (i, 0, 25) nxt[n][i] = last[i] = n + 1;
	per (i, n-1, 0) {
		last[s[i+1]-'a'] = i + 1;
		rep (j, 0, 25) nxt[i][j] = last[j];
	}
	memset(f, 0x3f, sizeof f); f[n+1] = 0;
	per (i, n, 0) rep (j, 0, 25)
		f[i] = min(f[i], f[nxt[i][j]] + 1);
	int cur = 0;
	while (cur <= n)
		rep (i, 0, 25) if (f[cur] == f[nxt[cur][i]] + 1) {
			putchar('a' + i); cur = nxt[cur][i]; break;
		}
	return 0;
}