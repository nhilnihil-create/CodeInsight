#include <bits/stdc++.h>

typedef long long LL;

#define FOR(i, a, b) for (int i = (a), i##_END_ = (b); i <= i##_END_; i++)
#define DNF(i, a, b) for (int i = (a), i##_END_ = (b); i >= i##_END_; i--)

template <typename Tp> void in(Tp &x) {
	char ch = getchar(), f = 1; x = 0;
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') ch = getchar(), f = -1;
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
}

template <typename Tp> void out(Tp x) {
	if (x > 9) out(x / 10);
	putchar(x % 10 + '0');
	return;
}

template <typename Tp> Tp Max(const Tp &x, const Tp &y) {return x > y ? x : y;}
template <typename Tp> Tp Min(const Tp &x, const Tp &y) {return x < y ? x : y;}
template <typename Tp> bool chkmax(Tp &x, Tp y) {return x >= y ? 0 : (x=y, 1);}
template <typename Tp> bool chkmin(Tp &x, Tp y) {return x <= y ? 0 : (x=y, 1);}

const int MAXN = 300010;

int n, m, tag[MAXN << 2];

struct Interview {
	int l, r;
} inter[MAXN];

bool cmp(const Interview &x, const Interview &y)
{
	return x.r - x.l + 1 < y.r - y.l + 1;
}

void modify(int now, int l, int r, int x, int y)
{
	if (x <= l && r <= y) tag[now]++;
	else {
		int mid = (l + r) >> 1;
		if (x <= mid) modify(now << 1, l, mid, x, y);
		if (mid < y) modify(now << 1 | 1, mid + 1, r, x, y);
	}
}

int query(int now, int l, int r, int x)
{
	if (l == r) return tag[now];
	int mid = (l + r) >> 1;
	if (x <= mid) return tag[now] + query(now << 1, l, mid, x);
	return tag[now] + query(now << 1 | 1, mid + 1, r, x);
}

int main()
{
	in(n); in(m);
	FOR(i, 1, n) in(inter[i].l), in(inter[i].r);

	std::sort(inter + 1, inter + n + 1, cmp);

	int now = 0;
	
	FOR(i, 1, m) {
		while (now < n && inter[now + 1].r - inter[now + 1].l + 1 < i) {
			modify(1, 1, m + 1, inter[now + 1].l + 1, inter[now + 1].r + 1);
			now++;
		}
		int ans = n - now;
		for (int j = 0; j <= m; j += i) ans += query(1, 1, m + 1, j + 1);
		printf("%d\n", ans);
	}

	return 0;
}
