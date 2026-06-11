#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;
const int MAXM = 1e5 + 10;

int n, m, bit[MAXM];
struct Triple {
	int l, r, len;
	
	Triple() {}
	Triple(int _l, int _r, int _len) : l(_l), r(_r), len(_len) {}
} a[MAXN];

inline bool cmp(const Triple &x, const Triple &y) {
	return x.len < y.len;
}

void add(int x, int v) {
	for (; x <= m; x += x & -x)
		bit[x] += v;
}

int get(int x) {
	int r = 0;
	for (; x; x -= x & -x)
		r += bit[x];
	return r;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		a[i] = Triple(l, r, r - l + 1);
	}
	sort(a + 1, a + n + 1, cmp);
	int ptr = 1;
	for (int i = 1; i <= m; ++i) {
		for (; ptr <= n && a[ptr].len < i; ++ptr) {
			add(a[ptr].l, 1);
			add(a[ptr].r + 1, -1);
		}
		int ans = n - ptr + 1;
		for (int j = i; j <= m; j += i)
			ans += get(j);
		printf("%d\n", ans);
	}
}