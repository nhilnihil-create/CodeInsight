#include <bits/stdc++.h>

const int kN = 1e5 + 5;

int dg[kN], n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int a, b; scanf("%d%d", &a, &b);
		++dg[a]; ++dg[b];
	}
	bool flag = true;
	for(int i = 1; i <= n; ++i) {
		if(dg[i] % 2 != 0) flag = false;
	}
	printf(flag ? "YES\n" : "NO\n");
	return 0;
}