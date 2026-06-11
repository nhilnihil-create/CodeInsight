#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,m,R;
    cin >> n >> m >> R;
    vector<ll> r(R);
    for(i = 0;i < R;++i){
        cin >> r.at(i);
        --r.at(i);
    }
    sort(all(r));
    vector<vector<ll>> graph(n,vector<ll> (n,1e9+7));
    for(i = 0;i < n;++i){
        graph.at(i).at(i) = 0;
    }
    for(i = 0;i < m;++i){
        ll a,b,c;
        cin >> a >> b >> c;
        --a;    --b;
        graph.at(a).at(b) = c;
        graph.at(b).at(a) = c;
    }
    ll k;
    rep(k,n){
        for(i = 0;i < n;++i){
            rep(j,n){
                graph.at(i).at(j) = min(graph.at(i).at(j), graph.at(i).at(k) + graph.at(k).at(j));
            }
        }
    }
    ll ans = 1e9 + 7;
    do{
        ll tmp = 0;
        for(i = 0;i < R-1;++i){
            ll s = r.at(i);
            ll g = r.at(i+1);
            tmp += graph.at(s).at(g);
        }
        ans = min(ans, tmp);
    }while(next_permutation(all(r)));
    cout << ans << endl;
    return 0;
}