//### In The Name Of GOD ###

//%% Remember; (((He))) is The (((Accepter))) %%

// GOD IS GREATER ...

#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;

#define sz(a) (int)(a.size())

const int MAXN = 1e5 + 10, MAXD = 11;
int mark[MAXN], ans[MAXN];

struct relax{
	int v, d, c;
} a[MAXN];

vector <int> adj[MAXN];

void bfs(int v, int d, int c) {
	if(mark[v] >= d)
		return ;
	if(!ans[v])
		ans[v] = c;
	mark[v] = d;
	queue <pair <int, int>> q;
	q.push({v, d});
	while(sz(q)) {
		int v = q.front().first;
		int d = q.front().second;
		if(!ans[v])
			ans[v] = c;
		for(int i : adj[v]) {
			if(mark[i] < d - 1) {
				mark[i] = d - 1;
				q.push({i, d - 1});
			}
		}
		q.pop();
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		cin >> a[i].v >> a[i].d >> a[i].c;
		a[i].v --;
	}
	for(int i = 0; i < n; i++)
		mark[i] = -1;
	reverse(a, a + q);
	for(int i = 0; i < q; i++) {
		bfs(a[i].v, a[i].d, a[i].c);
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << '\n' ;
}


