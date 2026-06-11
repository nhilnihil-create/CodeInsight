#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define FF first
#define SS second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pie;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll LINF = 4e18;
const ll delta = 96181;

struct node {
	int v;
	int d;
	int c;
};

const int N = 1e5 + 20;
vector<int> G[N];
vector<node> Q;
int n, m, ans[N], q;
bool mark[N][11];

void go(int v, int d, int c) {
	if (mark[v][d] || d < 0) return ;
	mark[v][d] = 1;
	if (d == 0)
		ans[v] = c;
	go(v, d - 1, c);
	for (int u : G[v])
		go(u, d - 1, c);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0, v, u; i < m; i++) {
		cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	cin >> q;
	for (int i = 0, v, d, c; i < q; i++) {
		cin >> v >> d >> c;
		Q.push_back({v, d, c});
	}	
	for (int i = Q.size() - 1; i >= 0; i--)
		go(Q[i].v, Q[i].d, Q[i].c);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;
}

