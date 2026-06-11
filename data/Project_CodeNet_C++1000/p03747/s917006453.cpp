#include <bits/stdc++.h>

typedef long long LL;

#define FOR(i, a, b) for (LL i = (a), i##_END_ = (b); i <= i##_END_; i++)
#define DNF(i, a, b) for (LL i = (a), i##_END_ = (b); i >= i##_END_; i--)

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

const LL MAXN = 100010;

LL n, l, t, pos[MAXN], rnk[MAXN], pre[MAXN];

bool cmp(const LL &x, const LL &y)
{
	return pre[x] < pre[y];
}

int main()
{
	in(n); in(l); in(t);

	LL radix = 0;
	
	FOR(i, 1, n) {
		LL x, w; in(x); in(w);
		pre[i] = x;
		if (w == 1) {
			pos[i] = (x + t) % l;
			radix += (x + t) / l;
			radix = (radix % n + n) % n;
		}
		else {
			pos[i] = ((x - t) % l + l) % l;
			if (x - t < 0) radix -= (t - x - 1) / l + 1;
			radix = (radix % n + n) % n;
		}
	}

	FOR(i, 1, n) rnk[i] = i;
	std::sort(rnk + 1, rnk + n + 1, cmp);

	radix %= n;

	std::sort(pos + 1, pos + n + 1);

	FOR(i, 1, n) {
		printf("%lld\n", pos[((rnk[i] + radix - 1) % n + n) % n + 1]);
	}
	
	return 0;
}
