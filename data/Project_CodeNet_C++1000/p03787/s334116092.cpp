#include <bits/stdc++.h>
#define int long long
#define P(x) cout << x << endl
#define D(x) P(#x << ": " << x)
#define F(i,n) for (int i=0; i<(int)(n); i++)
#define DEC(i,n) for (int i=(int)(n); --i>=0;)
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
const int N=100000;

vector<int> adj[N];
int col[N];

bool bipa(int u, int c) {
    if (col[u]) return col[u] == c;
    col[u] = c;
    bool ok=true;
    for (int v : adj[u])
        if (!bipa(v, 3-c))
            ok=false;
    return ok;
}

signed main() {
    int n,m; cin>>n>>m;
    F(i,m) {
        int a,b; cin>>a>>b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int alone=0, bip=0, other=0;
    F(i,n) if (!col[i]) {
        if (adj[i].empty()) {
            col[i] = 1;
            alone++;
        } else if (bipa(i, 1))
            bip++;
        else
            other++;
    }
    int res = n*n - (n-alone)*(n-alone);
    res += (other+bip)*(other+bip) + bip*bip;
    P(res);
}