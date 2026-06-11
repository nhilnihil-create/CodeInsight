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

const int N = 3e5 + 233;
int n, vis[N], rem[N], ans[N];
map <int, int> alive;
pair <int, int> a[N];

#define GG (puts("No"), exit(0))

signed main(void) {
	read(n);
	rep (i, n) {
		read(a[i].first), a[i].second = i;
		if (vis[a[i].first]) GG;
		vis[a[i].first] = i;
	}
	sort(a + 1, a + n + 1);
	rep (i, n) rem[a[i].second] = a[i].second - 1;
	int pos = 1;
	for (int i = 1; i <= n * n; i++) {
		if (vis[i]) {
			if (rem[vis[i]]) GG;
			ans[i] = vis[i];
			if (vis[i] != n) alive[vis[i]] = n - vis[i];
		}
		else {
			while (pos <= n && !rem[a[pos].second]) ++pos;
			if (pos <= n) {
				--rem[a[pos].second]; ans[i] = a[pos].second;
			} else {
				auto it = alive.begin();
				if (it == alive.end()) GG;
				ans[i] = it->first;
				if (--it->second == 0) alive.erase(it);
			}
		}
	}
	cout << "Yes\n";
	rep (i, n * n) cout << ans[i] << " "; cout << "\n";
}
