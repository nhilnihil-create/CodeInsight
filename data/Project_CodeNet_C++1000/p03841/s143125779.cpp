#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
int n, c[MAXN], x[MAXN], y[MAXN], ans[MAXN*MAXN], bin[MAXN*MAXN], cur;
inline bool cmp(int i, int j) { return x[i]<x[j]; }
int main () {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &x[i]), c[i] = i, ans[x[i]] = i;
	sort(c+1, c+n+1, cmp);
	for(int i = 1, j = 1; i <= n*n; ++i) {
		for(; j <= n && y[c[j]] == c[j]-1; ++j);
		if(ans[i]) {
			if(y[ans[i]] != ans[i]-1) { puts("No"); return 0; }
			++y[ans[i]];
			while(y[ans[i]] < n) ++y[ans[i]], bin[++cur] = ans[i];
		}
		else if(j > n) {
			if(!cur) { puts("No"); return 0; }
			ans[i] = bin[cur--];
		}
		else {
			ans[i] = c[j]; ++y[c[j]];
		}
	}
	puts("Yes");
	for(int i = 1; i <= n*n; ++i) printf("%d%c", ans[i], " \n"[i==n*n]);
}
