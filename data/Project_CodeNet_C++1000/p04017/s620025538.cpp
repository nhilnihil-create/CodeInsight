#include <bits/stdc++.h>
using namespace std;

#define MX 100050
int x[MX];
int f[18][MX];

int main() {
	int n, L, q;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", x + i);
	scanf("%d%d", &L, &q);
	for(int i = 0; i < n; i++) {
		int p = upper_bound(x, x + n, x[i] + L) - x; p--;
		f[0][i] = p;
	}
	for(int i = 1; i < 18; i++)
		for(int j = 0; j < n; j++) f[i][j] = f[i - 1][f[i - 1][j]];
	while(q--) {
		int s, t; scanf("%d%d", &s, &t); s--; t--;
		if(s > t) swap(s, t);
		int res = 0;
		for(int i = 17; i >= 0; i--) {
			if(f[i][s] < t) s = f[i][s], res ^= 1 << i;
		}
		printf("%d\n", res + 1);
	}
	return 0;
}