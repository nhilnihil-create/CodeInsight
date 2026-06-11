#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = (1<<30);

void Warshall_Floyd (vector<vector<ll>>& distance){
    ll n = distance.size();
    for(ll i = 0; i < n; i++) distance[i][i] = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            for(ll k = 0; k < n; k++){
                distance[j][k] = min(distance[j][i]+distance[i][k],distance[j][k]);
            }
        }
    }
}

ll Factorial (ll n){
    ll res = 1;
    for(ll i = 0; i < n; i++) res *= i+1;
    return res;
}

int main(){
    ll n,m,r;
    cin >> n >> m >> r;
    vector<ll> g(r);
    for(ll i = 0; i < r; i++){
        ll d;
        cin >> d;
        d--;
        g[i] = d;
    }
    vector<vector<ll>> dist(n,vector<ll>(n,INF));
    for(ll i = 0; i < m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        dist[a][b] = min(c,dist[a][b]);
        dist[b][a] = min(c,dist[b][a]);
    }
    Warshall_Floyd(dist);
    ll ans = INF;
    for(ll i = 0; i < Factorial(r); i++){
        ll can = 0;
        for(ll i = 0; i < r-1; i++){
            can += dist[g[i]][g[i+1]];
        }
        if(ans > can) ans = can;
        next_permutation(g.begin(),g.end());
    }
    cout << ans << endl;
    return 0;
}