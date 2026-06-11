#include <iostream>
#include <cstdio>

#define F(i, a, b) for (LL i = a; i <= b; i ++)
#define G(i, a, b) for (LL i = a; i >= b; i --)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mem(a, b) memset(a, b, sizeof a)
#define mn(a, b) ((a) = min(a, b))
#define mx(a, b) ((a) = max(a, b))
#define sf scanf
#define pf printf
#define bb puts("")

typedef long long LL;

using namespace std;

const LL N = 1e5 + 10;

LL n, m, Ans, Max;
LL a[N], S[N], T[N];

LL Doit(LL x, LL y) {
	return y >= x ? y - x : y + m - x;
}

int main() {
	sf("%lld %lld", &n, &m);
	F(i, 1, n) sf("%lld", &a[i]);
	F(i, 1, n - 1) {
		LL w = Doit(a[i], a[i + 1]);
		if (a[i + 1] > a[i]) {
			LL v = w - (a[i + 1] /* - T */ + 1);
			S[a[i] + 1] += v, S[a[i + 1] + 1] -= v;
			T[a[i] + 1] += 1, T[a[i + 1] + 1] -= 1;
		}
		else
		{
			LL v = w - (a[i + 1] + m + 1);
			// a[i] + 1 .. m
			S[a[i] + 1] += v, S[m + 1] -= v;
			T[a[i] + 1] += 1, T[m + 1] -= 1;

			// 0.. a[i + 1]
			v = w - (a[i + 1] + 1);
			S[0] += v, S[a[i + 1] + 1] -= v;
			T[0] += 1, T[a[i + 1] + 1] -= 1;
		}
		Ans += w;
	}
	F(i, 0, m) {
		S[i] += S[i - 1], T[i] += T[i - 1];
		mx(Max, S[i] + T[i] * i);
	}
	pf("%lld\n", Ans - Max);
}