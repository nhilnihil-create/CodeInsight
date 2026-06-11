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

const int N = 1e6 + 233;
int n, m, x, p[N], a[N], b[N], ans[N];
#define GG (puts("No"), exit(0))
signed main(void) {
	read(n); read(x);
	m = 2 * n - 1;
	if (n == 1) {
		if (x != 1) GG;
		cout << "1\n";
	} else {
		if (x == 1 || x == m) GG;
		ans[n - 1] = 1;
		ans[n] = x;
		ans[n + 1] = m;
		priority_queue <int> S;
		rep (i, m) {
			if (i == 1 || i == m || i == x) continue;
			S.push(i);
		}
		rep (i, n - 2) ans[i] = S.top(), S.pop();
		rep (i, n - 2) ans[m - i + 1] = S.top(), S.pop();
		cout << "Yes\n";
		rep (i, m) cout << ans[i] << "\n";
	} 
	
	// rep (i, m) a[i] = i;
	// set <int> s;
	// do {
	// 	vector <int> b(a + 1, a + m + 1);
	// 	int l = m;
	// 	while (l > 1) {
	// 		vector <int> c;
	// 		for (int k = 0; k + 2 < l; k++) {
	// 			int t[] = {b[k], b[k + 1], b[k + 2]};
	// 			sort(t, t + 3);
	// 			c.push_back(t[1]);
	// 		}
	// 		swap(c, b);
	// 		l = b.size();
	// 	}
	// 	s.insert(b.front());
	// } while (next_permutation(a + 1, a + m + 1));
	// for (int i : s) cout << i << " "; cout << "\n";
	
}
