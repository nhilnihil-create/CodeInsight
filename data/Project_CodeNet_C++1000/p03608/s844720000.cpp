#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

const ll INF = 100100100100100;

ll mmin(ll a, ll b){
    if(a > b) return b;
    else return a;
}

int main(){
    ll n, m, r; cin >> n >> m >> r;
    vector<ll> data(r);
    rep(i,r){
        ll rr;
        cin >> rr;
        data[i] = rr-1;
    }
    sort(all(data));
    vector<vector<ll>> dist(n,vector<ll>(n,INF));
    rep(i,m){
        ll a, b, c; cin >> a >> b >> c;
        dist[a-1][b-1] = c;
        dist[b-1][a-1] = c;
    }
    rep(i,n) dist[i][i] = 0;

    rep(k,n) rep(i,n) rep(j,n) dist[i][j] = mmin(dist[i][j], dist[i][k] + dist[k][j]);

    ll ans = INF;  
    do{
        ll count = 0;
        rep(i,r-1) count += dist[data[i]][data[i+1]];
        if(ans > count) ans = count;
    }while(next_permutation(all(data)));
  	cout << ans << endl;    
}