#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
vector<vector<ll>> d(205,vector<ll>(205,1e9));
void warshall_floyd(ll n) {
    for (ll i = 0; i < n; i++)      
        for (ll j = 0; j < n; j++) 
            for (ll k = 0; k < n; k++) 
                chmin(d[i][j], d[i][k] + d[k][j]);
}
int main(){
    ll n,m,r; cin>>n>>m>>r;
    vector<ll> city(r);
    rep(i,r){
        cin>>city[i];
        city[i]--;
    }
    rep(i,m){
        ll a,b,c; cin>>a>>b>>c;
        a--; b--;
        d[a][b]=c; d[b][a]=c;
    }
    rep(i,n) d[i][i]=0;
    warshall_floyd(n);
    warshall_floyd(n);
    warshall_floyd(n);
    ll res=1e10;
    vector<ll> v(r,0);
    rep(i,r) v[i]=i;
    do{
        ll tmp=0;
        rep(i,r-1) tmp+=d[ city[v[i]] ][ city[v[i+1]] ];
        chmin(res,tmp);
    }while(next_permutation(v.begin(),v.end()));
    cout<<res<<endl;
    return 0;
}