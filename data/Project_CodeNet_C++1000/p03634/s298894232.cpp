#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 998244353;
using ll = long long;
using P = pair<ll, ll>;
double PI = acos(-1);

int n;
int a, b, c;
vector<vector<P>> to(MX);
int q,k;
int x[MX], y[MX];
int vis[MX];
int dep[MX];

void dfs(int v, int depth) {
    if(vis[v]==1) return;
    vis[v] = 1;
    dep[v] = depth;
    for(auto u: to[v]) {
        dfs(u.first, depth+u.second);
    }
}

signed main(){
    cin >> n;
    rep(i,n-1) {
        cin >> a >> b >> c;
        to[a].push_back({b,c});
        to[b].push_back({a,c});
    }
    cin >> q >> k;
    dfs(k,0);
    
    rep(i, q) {
        cin >> x[i] >> y[i];
        cout << dep[x[i]]+dep[y[i]] << endl;
    }
    return 0;
}

