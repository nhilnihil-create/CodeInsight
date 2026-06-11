#include<bits/stdc++.h>

#define LL long long
#define RG register

using namespace std;
template<class T> inline void read(T &x) {
	x = 0; RG char c = getchar(); bool f = 0;
	while (c != '-' && (c < '0' || c > '9')) c = getchar(); if (c == '-') c = getchar(), f = 1;
	while (c >= '0' && c <= '9') x = x*10+c-48, c = getchar();
	x = f ? -x : x;
	return ;
}
template<class T> inline void write(T x) {
	if (!x) {putchar(48);return ;}
	if (x < 0) x = -x, putchar('-');
	int len = -1, z[20]; while (x > 0) z[++len] = x%10, x /= 10;
	for (RG int i = len; i >= 0; i--) putchar(z[i]+48);return ;
}
const int N = 1e5 + 10;
int nxt[17][N], x[N], n, L, Q;
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) read(x[i]);
	read(L);
	for (int i = 1; i <= n; i++)
		nxt[0][i] = upper_bound(x + 1, x + n + 1, x[i] + L) - x - 1;
	for (int i = 1; i <= 16; i++)
		for (int j = 1; j <= n; j++)
			nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
	read(Q);
	while (Q--) {
		int a, b;
		read(a); read(b);
		if (a > b) swap(a, b);
		if (a < b) {
			int ans = 0;
			for (int i = 16; i >= 0; i--)
				if (nxt[i][a] < b)
					a = nxt[i][a], ans += (1 << i);
			printf("%d\n", ans + 1);
		}
	}
	return 0;
}
