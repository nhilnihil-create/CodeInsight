#include <bits/stdc++.h>
#define rep(i, a) for(auto i=0; i<a; i++)
#define rep1(i, a, b) for(auto i=a; i<b; i++)
#define p_b push_back
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
 
int main() {
    ll n, m, t;
    cin>>n>>m>>t;
    vvi g(n, vi(n, INT_MAX));
    vi r(t);
    rep(i, t)
        cin>>r[i];
    sort(r.begin(), r.end());
    rep(i, n)
        g[i][i]=0;
    rep(i, m){
        ll x, y, w;
        cin>>x>>y>>w;
        x--;
        y--;
        if(g[x][y] > w)
            g[x][y] = g[y][x] = w;
    }
    rep(k, n)
        rep(i, n)
            rep(j, n)
                if(g[i][k]!=INT_MAX && g[k][j]!=INT_MAX)
                if(g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];
    ll ans = LLONG_MAX;
    do{
        ll cur = 0;
        rep(i, t-1){
            cur += g[r[i]-1][r[i+1]-1];
            // cout<<r[i]<<" ";
        }
        // cout<<r[t-1]<<endl;
        ans = min(ans, cur);
    }while(next_permutation(r.begin(), r.end()));
    cout<<ans<<endl;
    return 0;
}