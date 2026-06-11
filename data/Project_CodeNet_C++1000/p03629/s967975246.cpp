
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = int(2e5), alphsz = 26, inf = 0x3f3f3f3f;
int n, lst[alphsz + 5], g[nsz + 5][alphsz + 5], bad[nsz + 5], len[nsz + 5], pre[nsz + 5];
string s, ans;

void inline bfs(int s, int* dis) {
	static int q[nsz + 5];
	int ql = 0, qr = 0;
	q[qr++] = s;
	cont (i, n) {
		dis[i] = inf;
	}
	for (; ql != qr;) {
		int u = q[ql++];
		if (bad[u] != -1) {
			ans += bad[u] + 'a';
			for (; u; u = pre[u]) {
				ans += ::s[u - 1];
			}
			reverse(all(ans));
			cout << ans << ln;
			break;
		}
		loop (c, 26) {
			int v = g[u][c];
			if (v == inf || dis[v] != inf)  continue;
			dis[v] = dis[u] + 1;
			q[qr++] = v;
			pre[v] = u;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin >> s;
	n = int(s.size());
	memset(lst, inf, sizeof(lst));
	memset(bad, -1, sizeof(bad));
	for (int i = n; i >= 0; --i) {
		loop (c, 26) {
			g[i][c] = lst[c];
			if (g[i][c] == inf && bad[i] == -1)  bad[i] = c;
		}
		if (i) {
			int c = s[i - 1] - 'a';
			lst[c] = i;
		}
	}
	bfs(0, len);
}