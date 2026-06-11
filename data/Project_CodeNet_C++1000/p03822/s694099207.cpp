#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
using Graph = vector<vector<ll> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;

//input
ll n;
vector<ll>a;

Graph g;

vector<ll>dp;

ll rec(ll v,ll p){
    if(dp[v]>=0)return dp[v];
    ll res = 0;
    vector<ll>tmp;
    for(ll x:g[v]){
        if(x==p)continue;
        tmp.push_back(rec(x,v));
    } 
    sort(tmp.rbegin(),tmp.rend());
    rep(i,tmp.size()){
        chmax(res,tmp[i]+i+1);
    }
    return dp[v]=res;
}
int main(){
    //input
    cin >> n;
    g.resize(n);
    rep(i,n-1){
        int a;
        cin >> a;
        a--;
        g[i+1].push_back(a);
        g[a].push_back(i+1);
    }
    dp.resize(n,-1);
    cout << rec(0,-1) << endl;
    /*
    cout << endl;
    rep(i,n){
        cout << dp[i] << endl;
    }
    */
    return 0;
}
