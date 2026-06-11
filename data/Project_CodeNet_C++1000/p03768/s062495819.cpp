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
    int v, d, col;
 
    que() {
        v = d = col = 0;
    }
} req[MAXN];
 
vector<int> adj[MAXN];
 
int col[MAXN];
 
int lim[MAXN];
 
int u[MAXN];
 
int n, m, q;
 
int timer;
 
int main(){
    scanf("%d %d", &n, &m);
 
    for (int i = 1; i <= n; ++i) {
        lim[i] = -1;
        col[i] = 0;
        u[i] = 0;
    }
 
    for (int i = 1, u, v; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    scanf("%d", &q);
 
    for (int i = 1; i <= q; ++i) {
        scanf("%d %d %d", &req[i].v, &req[i].d, &req[i].col);
    }
 
    queue<pair<int, int> > Q;
 
    for (int i = q; i > 0; --i) {
        Q.push(mp(req[i].v, req[i].d));
        ++timer;
 				
        while (!Q.empty()) {
            int v = Q.front().fi;
            int d = Q.front().se;
 
            Q.pop();
 
            u[v] = timer;
 
            if (d <= lim[v]) {
                continue;
            }
 
            if (!col[v]) {
                col[v] = req[i].col;
            }
 
            lim[v] = d;
 
            for (int to : adj[v]) {
                if (u[to] != timer) {
                    Q.push(mp(to, d - 1));
                }
            }
        }
    }
 
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", col[i]);
    }
	return 0;
}