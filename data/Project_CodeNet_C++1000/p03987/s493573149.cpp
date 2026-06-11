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
const int N = 3e5 + 233;
int n, a[N], id[N];
int main(void) {
	read(n);
	rep (i, n) read(a[i]), id[a[i]] = i;
	set <int> S;
	lo ans = 0;
	rep (i, n) {
		auto it = S.lower_bound(id[i]);
		int l = 0, r = n + 1;
		if (it != S.end()) r = *it;
		if (it != S.begin()) l = *--it;
		ans += 1LL * i * (id[i] - l) * (r - id[i]);
		S.insert(id[i]);
	}
	cout << ans << "\n";
   
}
