#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=998244353;
const ll mod=1e9+7;
vector<vector<ll> >G(100010);
ll dfs(ll i,ll p){
    ll res=0;
    for(auto e:G[i]){
        if(e==p)continue;
        res^=(dfs(e,i)+1);
    }
    return res;
}
signed main(){
    ll n;cin>>n;
    rep(i,n-1){
        ll a,b;cin>>a>>b;
        a--;b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    ll ans=dfs(0,-1);
    if(ans)cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}