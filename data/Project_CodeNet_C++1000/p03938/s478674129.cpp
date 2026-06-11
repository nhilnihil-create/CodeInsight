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

const int N = 23333;
int n, p[N], a[N], b[N];

signed main(void) {
	read(n);
	rep (i, n) read(p[i]);
	rep (i, n) a[i] = b[n - i + 1] = (n + 1) * i;
	rep (i, n) a[p[i]] += i;
	rep (i, n) cout << a[i] << " \n"[i == n];
	rep (i, n) cout << b[i] << " \n"[i == n];
}
