#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 1e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n, m, ans[maxn], range[maxn];
int Q, v[maxn], c[maxn], d[maxn];
int q[maxn], ql, qr;
vector<int> graph[maxn];

void bfs(int u, int d, int c) {
	if (range[u] >= d) {
		return;
	}
	ql = qr = 0;
	q[qr++] = u;
	range[u] = d;
	if (ans[u] == -1) {
		ans[u] = c;
	}

	while (qr - ql > 0) {
		int now = q[ql++];
		for (int i : graph[now]) {
			if (range[i] < range[now] - 1) {
				range[i] = range[now] - 1;
				if (ans[i] == -1) {
					ans[i] = c;
				}
				q[qr++] = i;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(ans, -1, sizeof(ans));
	memset(range, -1, sizeof(range));

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> v[i] >> d[i] >> c[i];
		v[i]--;
	}

	for (int i = Q - 1; i >= 0; i--) {
		bfs(v[i], d[i], c[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << (ans[i] == -1 ? 0 : ans[i]) << endl;
	}
}

