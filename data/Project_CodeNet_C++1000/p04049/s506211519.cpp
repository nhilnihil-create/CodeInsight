#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

vi G[2005];

int dfs(int u, int p, int d) {
	int ret = 1;
	for(int v:G[u]) if(v != p && d)
		ret += dfs(v, u, d-1);
	return ret;
}

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}	
	if(k % 2 == 0) {
		int mx = -1;
		for(int i=1;i<=n;i++)
			mx = max(mx, dfs(i, -1, k/2));
		cout << n - mx << endl;
	} else {
		int mx = -1;
		for(int i=1;i<=n;i++)
			for(int j:G[i])
				mx = max(mx, dfs(i, j, k/2) + dfs(j, i, k/2));
		cout << n - mx << endl;
	}
	
}
