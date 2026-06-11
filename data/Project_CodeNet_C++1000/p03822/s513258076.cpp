#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf=1e9+7;
vector<vector<ll> >G(100010);
ll dfs(ll i){
    ll cnt=0;
    ll ma=-1;
    vector<ll>a(0);
    for(auto e:G[i]){
        cnt++;
        ll k=dfs(e);
        a.pb(k);
    }
    sort(all(a));
    rep(i,a.size()){
        if(a[i]>ma){
            ma=a[i];
            continue;
        }
        ma++;
    }
    //cout<<i<<' '<<ma<<endl;
    ll ret=ma+1;
    return ret;
}
int main(){
    ll n;cin>>n;
    ll a;
    rep(i,n-1){
        cin>>a;
        G[a].pb(i+2);
    }
    ll ans=dfs(1);
    cout<<ans<<endl;
}