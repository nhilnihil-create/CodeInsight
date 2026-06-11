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

#define GG (puts("Impossible"), exit(0))

const int N = 2333;
int n, mn, mx, a[N];
vector <int> dis[N], rol;

signed main(void) {
	read(n);
	rep (i, n) read(a[i]), dis[a[i]].push_back(i), mx = max(mx, a[i]);
	mn = (mx + 1) / 2;
	rep (k, mn - 1) if (dis[k].size()) GG;
	for (int k = mx; k >= mn; k--) {
		// cout << k << "\n";
		if (!dis[k].size()) GG;
		rol.push_back(dis[k].back()); dis[k].pop_back();
	}

	for (int k = mn + (!(mx & 1)); k <= mx; k++) {
		// cout << k << "\n";
		if (!dis[k].size()) GG;
		rol.push_back(dis[k].back()); dis[k].pop_back();
	}
	if (dis[mn].size()) GG;
	puts("Possible");
}
