#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
vector<vector<ll> >G(100010);
vector<vector<ll> >dp(100010,vector<ll>(11,0));
void solve(ll i,ll d,ll c){
    if(dp[i][d]){
        return;
    }
    dp[i][d]=c;
    if(d==0){
        return;
    }
    if(dp[i][d-1]==0)solve(i,d-1,c);
    for(auto e:G[i]){
        if(dp[e][d-1])continue;
        solve(e,d-1,c);
    }
    return;
}
signed main(){
    ll n,m;
    cin>>n>>m;
    rep(i,m){
        ll a,b;cin>>a>>b;
        a--;b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    ll q;cin>>q;
    vector<ll>v(q),d(q),c(q);
    rep(i,q){
        cin>>v[i]>>d[i]>>c[i];
        v[i]--;
    }
    for(int i=q-1;i>=0;i--){
        solve(v[i],d[i],c[i]);
    }
    rep(i,n){
        cout<<dp[i][0]<<endl;
    }
}