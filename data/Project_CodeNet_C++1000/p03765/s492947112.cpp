#include <bits/stdc++.h>

const int N = 100054;

int S, T;
char s[N], t[N];
int sa[N], ta[N];

int main() {
	int i, j, k, l, q;
	scanf("%s%s%d", s, t, &q), S = strlen(s), T = strlen(t);
	for (i = 0; i < S; ++i) sa[i + 1] = sa[i] + --s[i] % 3;
	for (i = 0; i < S; ++i) ta[i + 1] = ta[i] + --t[i] % 3;
	for (; q; --q)
		scanf("%d%d%d%d", &i, &j, &k, &l),
		puts((sa[j] - sa[--i] - ta[l] + ta[--k]) % 3 ? "NO" : "YES");
	return 0;
}