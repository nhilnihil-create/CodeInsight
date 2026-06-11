#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
using namespace std;

const int _ = 3e5 + 10;
int N, M, d;
struct node {
	int l, r, len;
} a[_];

struct BIT {
	int c[_];
	void insert(int x, int y) {
		for ( ; x <= M + 1; x += lowbit(x)) c[x] += y;
	}
	int query(int x) {
		int y = 0;
		for ( ; x; x -= lowbit(x)) y += c[x];
		return y;
	}
} tr;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &a[i].l, &a[i].r);
		a[i].len = (a[i].r - a[i].l + 1);
	}
	sort(a + 1, a + N + 1,
			 [](node a, node b) -> bool { return a.len < b.len; });
	for (int d = 1, p = 1; d <= M; ++d) {
		while (p <= N && a[p].len < d) {
			tr.insert(a[p].l, 1);
			tr.insert(a[p].r + 1, -1);
			++p;
		}
		int ans = N - p + 1;
		for (int i = d; i <= M; i += d)
			ans += tr.query(i);
		printf("%d\n", ans);
	}
	return 0;
}