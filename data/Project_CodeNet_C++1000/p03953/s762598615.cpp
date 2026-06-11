
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

namespace INPUT {
	const int L = 1 << 15;
	char _buf[L], *S, *T, c;
	char _gc () {
		if (S == T) {
			T = (S = _buf) + fread (_buf, 1, L, stdin);
			if (S == T) return EOF;
		}
		return *S++;
	}
	void readi (int &X) {
		bool flag;
		for (c = _gc (); (c < '0' || c > '9') && c != '-'; c = _gc ());
		if (c == '-') X = 0, flag = true; else X = c & 15, flag = false;
		for (c = _gc (); c >= '0' && c <= '9'; X = X * 10 + (c & 15), c = _gc ());
		if (flag) X = -X;
	}
	void readl (LL &X) {
		bool flag;
		for (c = _gc (); (c < '0' || c > '9') && c != '-'; c = _gc ());
		if (c == '-') X = 0, flag = true; else X = c & 15, flag = false;
		for (c = _gc (); c >= '0' && c <= '9'; X = X * 10 + (c & 15), c = _gc ());
		if (flag) X = -X;
	}
}
using INPUT :: readi;
using INPUT :: readl;

const int Maxn = 1E5 + 5;

int N, M; LL K;
int x[Maxn];
int a[Maxn];

int lnk[Maxn];
bool vis[Maxn];
int stk[Maxn], tp;

int ans[Maxn];

void Dfs (int u) {
	if (vis[u]) return ;
	vis[u] = true, stk[++tp] = u, Dfs (lnk[u]);
}

int main () {
	readi (N);
	for (int i = 1; i <= N; ++i)
		readi (x[i]), lnk[i] = i;
	readi (M), readl (K);
	for (int i = 1; i <= M; ++i)
		readi (a[i]), swap (lnk[a[i] - 1], lnk[a[i]]);
	memset (vis, false, sizeof (vis));
	for (int i = 1; i < N; ++i)
	if (!vis[i]) {
		tp = 0, Dfs (i);
		for (int j = 1; j <= tp; ++j)
			ans[stk[j]] = stk[(j + K - 1) % tp + 1];
	}
/*	for (int i = 1; i < N; ++i)
		cerr << lnk[i] << ' '; cerr<<endl;
	for (int i = 1; i < N; ++i)
		cerr << ans[i] << ' '; cerr<<endl;*/
	LL Ans = x[1];
	printf ("%lld\n", Ans);
	for (int i = 1; i < N; ++i)
		Ans += x[ans[i] + 1] - x[ans[i]],
		printf ("%lld\n", Ans);
	return 0;
}
