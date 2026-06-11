// Why am I so dumb? :c
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int MAXN = (int)2e3 + 5;

vector<int> adj[MAXN];
                
int dist[MAXN][MAXN];

bitset<2005> B[MAXN];

int n, k;

int ans;

void dfs(int v, int pr, int st, int d) {
	dist[st][v] = d;

	for (int to : adj[v]) {
		if (to == pr) {
			continue;
		}

		dfs(to, v, st, d + 1);
	}
}

void solve() {
	scanf("%d %d", &n, &k);

	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);		
	}	

	for (int i = 1; i <= n; ++i) {
		dfs(i, -1, i, 0);
	}

	int diameter = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			diameter = max(diameter, dist[i][j]);		
		}
	}

	k = min(k, diameter);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dist[i][j] > k) {
				B[i].set(j, 1);
			}
		}
	}

	ans = n - 1;

	for (int a = 1; a <= n; ++a) {
		for (int b = a + 1; b <= n; ++b) {
			int d = dist[a][b];

			if (d != k) {
				continue;
			}

			int cur = (B[a] | B[b]).count();            
			ans = min(ans, cur);
		}	
	}

	printf("%d\n", ans);
}

int main() {
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}