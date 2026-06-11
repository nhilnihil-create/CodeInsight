#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define mk make_pair
#define fi first
#define se second
#define N 300010
#define M 100010
int n, m;
pii a[N];

int q[M],  rt[M], L[M * 100], R[M * 100], t[M * 100], len = 0;
void add(int pre, int &now, int l, int r, int x) {
	now = ++ len; t[now] = t[pre] + 1;
	if (l == r) return ;
	int mid = (l + r) >> 1;
	if (x <= mid) add(L[pre], L[now], l, mid, x), R[now] = R[pre];
	else add(R[pre], R[now], mid + 1, r, x), L[now] = L[pre];
}
int query(int p, int l, int r, int ql, int qr) {
	if (!p) return 0;
	if (ql <= l && r <= qr) return t[p];
	int mid = (l + r) >> 1;
	int res = 0;
	if (ql <= mid) res += query(L[p], l, mid, ql, qr);
	if (mid < qr) res += query(R[p], mid + 1, r, ql, qr);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i].fi >> a[i].se;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) {
		if (i > 1) {
			for (int j = a[i - 1].fi + 1; j < a[i].fi; ++ j) rt[j] = rt[a[i - 1].fi];
		}
		add(rt[a[i - 1].fi], rt[a[i].fi], 1, m, a[i].se);
	}
	for (int j = a[n].fi + 1; j <= m; ++ j) rt[j] = rt[a[n].fi];
	for (int d = 1; d <= m; ++ d) {
		int ans = 0;
		for (int i = 1; i * d <= m; ++ i) {
			// l : [(i - 1) * d + 1, i * d] r : [i * d, m]
			ans += query(rt[i * d], 1, m, i * d, m);
			ans -= query(rt[(i - 1) * d], 1, m, i * d, m);
		}
		printf("%d\n", ans);
	}
	return 0;
}