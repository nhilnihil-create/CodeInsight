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

const LL MAXN = 100010;

LL n, m, k, y[MAXN], x[MAXN], z[MAXN], t[MAXN];

LL abs(LL x) {return x < 0 ? -x : x;}

int main()
{
	in(n);
	FOR(i, 1, n) in(x[i]);
	FOR(i, 1, n - 1) y[i] = x[i + 1] - x[i], z[i] = i;

	in(m); in(k);
	FOR(i, 1, m) {LL x; in(x); std::swap(z[x - 1], z[x]);}

	static LL ret[MAXN];
	FOR(i, 1, n - 1) ret[i] = i;

	while (k) {
		if (k & 1) FOR(i, 1, n - 1) ret[i] = z[ret[i]];
		FOR(i, 1, n - 1) t[i] = z[i];
		FOR(i, 1, n - 1) z[i] = t[t[i]];
		k >>= 1;
	}

	//if (x[1] < 0) putchar('-'); out(abs(x[1])); putchar(10);
	printf("%lld\n", x[1]);
	
	FOR(i, 1, n - 1) {
		x[i + 1] = x[i] + y[ret[i]];
		//if (x[i + 1] < 0) putchar('-'); out(abs(x[i + 1])); putchar(10);
		printf("%lld\n", x[i + 1]);
	}
	
	return 0;
}
