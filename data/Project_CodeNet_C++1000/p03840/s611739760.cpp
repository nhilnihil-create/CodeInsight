#include <bits/stdc++.h>
#define rep(i, n) for (rint i = 1; i <= (n); i ++)
#define re0(i, n) for (rint i = 0; i < (int) n; i ++)
#define travel(i, u) for (rint i = head[u]; i; i = e[i].nxt)
#define rint register int
using namespace std;

typedef long long lo;

template<typename tp> inline void read(tp &x) {
    x = 0; char c = getchar(); int f = 0;
    for (; c < '0' || c > '9'; f |= c == '-', c = getchar());
    for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
    if (f) x = -x;
}
#define int long long

inline int F(int x) { return (x / 2) * 2; }

signed main(void) {
	int ai, ao, at, aj, al, as, az, ans;
	read(ai); read(ao); read(at); read(aj); read(al); read(as); read(az);
	ans = ao;
	int res = 0;
	for (int k = 0; k <= min(3ll, min(ai, min(aj, al))); k++) {
		res = max(res, F(ai - k) + F(aj - k) + F(al - k) + k * 3);
	}
	cout << res + ans << "\n";
}
