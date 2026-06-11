#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100 * 1000 + 100;
vector <int> adj[MAXN];
bool p = true;
int good[MAXN], mark[MAXN], cnt[3];


void dfs(int v, bool b) {
	mark[v] = true;
	good[v] = b;
	for(int i : adj[v]) {
		if(!mark[i])
			dfs(i, !b);
		else if(good[i] == good[v])
			p = false;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		if (!mark[i]) {
			if (!adj[i].size()) {
				cnt[2]++;
				continue;
			}
			p = true;
			dfs(i, 0);
			cnt[p]++;
		}
	cerr << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << endl;
	ll ans = (ll)cnt[1] * cnt[1] * 2 + (ll)cnt[0] * cnt[1] * 2;
//	cerr << ans << endl;
	ans += (ll)cnt[2] * n * 2 - (ll)cnt[2] * cnt[2];
//	cerr << ans << endl;
	ans += cnt[0] * cnt[0] * 2 - cnt[0] * cnt[0];
	cout << ans << endl;
}
