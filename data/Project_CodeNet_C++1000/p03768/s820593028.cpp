// Why am I so dumb? :c
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int MAXN = (int)1e5 + 5;

struct que {
	int st, lim, c;

	que() {
		st = lim = c = 0;
	}
} req[MAXN];

vector<int> adj[MAXN];

int cover[MAXN];

int col[MAXN];

int u[MAXN];

int d[MAXN];

int n, m, q;

void solve() {                   
	scanf("%d %d", &n, &m);

    for (int i = 1, u, v; i <= m; ++i) {
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);    
    }

    scanf("%d", &q);

    for (int i = 1; i <= q; ++i) {
    	scanf("%d %d %d", &req[i].st, &req[i].lim, &req[i].c);    	    		
    }

    for (int i = 1; i <= n; ++i) {
    	cover[i] = -1;
    }

    queue<int> Q;

    for (int i = q; i > 0; --i) {
    	int st = req[i].st, lim = req[i].lim, c = req[i].c;        

		Q.push(st);
    	d[st] = 0;
    	u[st] = i;

    	while (!Q.empty()) {
			int v = Q.front();
			Q.pop();

			if (!col[v]) {
				col[v] = c;
			}

			if (lim - d[v] <= cover[v]) {
				continue;
			}

			cover[v] = lim - d[v];

			if (d[v] != lim) {
    			for (int to : adj[v]) {
    				if (u[to] != i) {
    					u[to] = i;
    					d[to] = d[v] + 1;
    					Q.push(to);
    				}
    			}
    		}
    	}    	
    }

    for (int i = 1; i <= n; ++i) {
    	printf("%d\n", col[i]);
    }
}

int main() {    
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}