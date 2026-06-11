#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 5e3 + 5;
const int P = 1e9 + 7;

int n, f[maxn][maxn], len;

char s[maxn];

inline int read() {
	char ch = getchar(); int u = 0, f = 1;
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) {u = u * 10 + ch - 48;  ch = getchar();} return u * f;
}

inline int ksm(int x, int k) {
	int cnt = 1;
	while(k) {
		if(k & 1) cnt = 1ll * cnt * x % P;
		x = 1ll * x * x % P; k >>= 1;
	} return cnt;
}

inline int pls(int x, int y) {x += y; return x >= P ? x - P : x;}

int main() {
	n = read(); scanf("%s", s + 1);
	len = strlen(s + 1);
	/*for(register int i = 1; i <= len; i++) s[i] -= '0';

	f[1][0][0] = 1;
	f[1][1][0] = 1; f[1][1][1] = 1;

	for(register int i = 2; i <= n; i++) {
		int t = i & 1, t0 = t ^ 1;

		memset(f[t], 0, sizeof(f[t]));

		for(register int j = 0; j <= i; j++) {
			if(j <= 0) {
				f[t][j][0] = pls(f[t0][1][0], f[t0][1][1]);
				f[t][j][0] = pls(f[t][j][0], f[t0][j][0]); continue;
			}
			int p0 = s[j - 1] << 1;
			f[t][j][p0] = pls(f[t0][j + 1][0], f[t0][j + 1][1]);
			f[t][j][p0 | 1] = pls(f[t0][j + 1][2], f[t0][j + 1][3]);
			if(j > 1) {
				int p1 = s[j - 2] << 1;
				f[t][j][0] = pls(f[t][j][0], f[t0][j - 1][p1]);
				f[t][j][1] = pls(f[t][j][1], f[t0][j - 1][p1]);
				f[t][j][2] = pls(f[t][j][2], f[t0][j - 1][p1 | 1]);
				f[t][j][3] = pls(f[t][j][3], f[t0][j - 1][p1 | 1]);
			} else {
				f[t][j][0] = pls(f[t][j][0], f[t0][j - 1][0]);
				f[t][j][1] = pls(f[t][j][1], f[t0][j - 1][0]);
			}
		}
	}

	cout << f[n & 1][len][s[len] | (s[len - 1] << 1)];*/
	
	f[0][0] = 1;
	for(register int i = 1; i <= n; i++)
		for(register int j = 0; j <= i; j++) {
			if(j > 0)
				f[i][j] = pls(f[i][j], f[i - 1][j - 1] * 2 % P);
			else f[i][j] = pls(f[i][j], f[i - 1][j]);
			f[i][j] = pls(f[i][j], f[i - 1][j + 1]);
		}
	
	cout << (1ll * f[n][len] * ksm(ksm(2, len), P - 2) % P);
	return 0;
}
