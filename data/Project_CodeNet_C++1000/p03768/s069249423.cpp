#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pi;

#define cerr if(0) cout	

const int MAXN = 200005;

vector<int> adj[MAXN];
int num[MAXN], col[MAXN];
vector<tuple<int,int,int> > que;

void dfs(int x, int d, int c) {
	if (!col[x]) col[x] = c;
	if (num[x] >= d) return;
	num[x] = d;
	if (!d) return;
	for (auto it: adj[x]) {
		dfs(it,d-1,c);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].emplace_back(v);	
		adj[v].emplace_back(u);
	}	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int u,d,c;
		cin >> u >> d >> c;
		que.emplace_back(u,d,c);
	}
	for (int i = q-1; i >=0; --i)  {
		int u,d,c;
		tie(u,d,c) = que[i];
		dfs(u,d,c);
	}
	for (int i = 1; i <= n; ++i) cout << col[i] << '\n';
    return 0;
}
