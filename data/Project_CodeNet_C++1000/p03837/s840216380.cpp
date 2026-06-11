#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 1e9+7
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<pint>>;

int main(){
    int N,M; cin>>N>>M;
    vector<vector<ll>> dist(N,vector<ll>(N,INF));
    rep(i,N){
        rep(j,N){
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    
    vector<ll> a(M),b(M),c(M);
    rep(i,M){
        cin>>a[i]>>b[i]>>c[i];
        --a[i]; --b[i];
        dist[a[i]][b[i]] = c[i];
        dist[b[i]][a[i]] = c[i];
    }

    rep(k,N){
        rep(i,N){
            rep(j,N){
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    int res = 0;
    rep(i,M){
        if(c[i]>dist[a[i]][b[i]])++res;
    }
    cout<<res<<endl;
}