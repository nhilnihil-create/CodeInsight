//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};
vvl G(114514);
vl flag(114514);
vl dp(114514);
ll dfs(ll now,ll pr){
    if(flag[now])return dp[now];
    flag[now]=1;
    vl res;
    for(auto to:G[now]){
        if(to==pr)continue;
        res.push_back(dfs(to,now));
    }
    if(res.size()==0)return dp[now]=0;
    ll fan=0;
    sort(res.begin(),res.end());
    reverse(res.begin(),res.end());
    rep(i,res.size())fan=max(fan,res[i]+i+1);
    return dp[now]=fan;
}
int main(){
    ll n;cin>>n;
    for(ll i=1;i<n;i++){
        ll a;cin>>a;a--;
        G[a].push_back(i);
    }
    cout<<dfs(0,-1)<<endl;
}

