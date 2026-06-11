#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> P;
const int maxn = 500, maxm = maxn * maxn;
int n, m, res[maxm + 3];
P a[maxn + 3];

int main() {
	scanf("%d", &n);
	m = n * n;
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		if (res[x]) puts("No"), exit(0);
		res[x] = i;
		a[i] = make_pair(x, i);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) if (a[i].se != 1) {
		int x = a[i].se - 1;
		for (int j = 1; j < a[i].fi; j++) if (!res[j]) {
			res[j] = a[i].se, x--;
			if (!x) break;
		}
		if (x > 0) puts("No"), exit(0);
	}
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) if (a[i].se != n) {
		int x = n - a[i].se;
		for (int j = m; j > a[i].fi; j--) if (!res[j]) {
			res[j] = a[i].se, x--;
			if (!x) break;
		}
		if (x > 0) puts("No"), exit(0);
	}
	puts("Yes");
	for (int i = 1; i <= m; i++) printf("%d%c", res[i], " \n"[i == m]);
	return 0;
}