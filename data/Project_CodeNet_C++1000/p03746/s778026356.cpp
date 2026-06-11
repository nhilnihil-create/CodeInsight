//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 17;

int n, m;
vector<int> adj[MAXN];
bool mark[MAXN];
deque<int> ans;

void dfs_1(int v) {
	mark[v] = true;
	for (auto i : adj[v])
		if (!mark[i]) {
			ans.pb(i);
			dfs_1(i);
			break;
		}
}
void dfs_2(int v) {
	mark[v] = true;
	for (auto i : adj[v])
		if (!mark[i]) {
			ans.push_front(i);
			dfs_2(i);
			break;
		}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int v, u;
		cin >> v >> u;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	ans.pb(1);
	dfs_1(1);
	dfs_2(1);
	cout << ans.size() << endl;
	for (auto i : ans)
		cout << i << ' ';
	return 0;
}
