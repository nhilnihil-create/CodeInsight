#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j,k;
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> graph(n,vector<ll>(n,1e9));
    for(i = 0;i < n;++i){
        graph.at(i).at(i) = 0;
    }
    vector<ll> a(m);
    vector<ll> b(m);
    vector<ll> c(m);
    for(i = 0;i < m;++i){
        cin >> a.at(i) >> b.at(i) >> c.at(i);
        --a.at(i);  --b.at(i);
        graph.at(a.at(i)).at(b.at(i)) = c.at(i);
        graph.at(b.at(i)).at(a.at(i)) = c.at(i);
    }
    rep(k,n){
        for(i = 0;i < n;++i){
            rep(j,n){
                graph.at(i).at(j) = min(graph.at(i).at(j), graph.at(i).at(k) + graph.at(k).at(j));
            }
        }
    }
    ll ans = 0;
    for(i = 0;i < m;++i){
        if(graph.at(a.at(i)).at(b.at(i)) < c.at(i)) ++ans;
    }
    cout << ans << endl;

    return 0;
}