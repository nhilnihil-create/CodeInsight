#include <bits/stdc++.h>
#define pb push_back
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int n;
vector<vi> adj;
vll a;

ll dfs(int x, int p) {
    vll r;
    ll t, s=0, m=-1;
    for(int y:adj[x]) if(y!=p) {
        t=dfs(y, x);
        if(t<0) return -1;
        s+=t;
        m=max(m, t);
    }
    if(m==-1) return a[x];
    t=s-a[x];
    if(t<0 || (m>s-m && s-m<t)) return -1;
    return s-2*t;
}

int main() {
    int i, u, v;
    scanf("%d", &n);
    a.assign(n+1, 0);
    for(i=1; i<=n; i++) scanf("%lld", &a[i]);
    adj.assign(n+1, vi(0));
    for(i=1; i<=n-1; i++) {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(i=1; i<=n; i++) if(sz(adj[i])==1) break;
    printf(dfs(i, 0)>=0? "YES\n" : "NO\n");
    return 0;
}