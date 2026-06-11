#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll merge(ll x,ll y){
    if(x>=y) return x+1;
    else return y;
}
ll add_root(ll x){
    return x+1;
}
vec G[200001],dp(200001);
void dfs(int v,int p=-1){
    if(p!=-1&&G[v].size()==1){
        dp[v]=0;
        return;
    }
    ll ans=-1;
    vec A;
    for(auto i:G[v]){
        if(i==p) continue;
        dfs(i,v);
        A.push_back(dp[i]);
    }
    sort(all(A));
    for(auto i:A) ans=merge(ans,i);
    dp[v]=add_root(ans);
}
int main(){
    int n,a;
    cin>>n;
    rep(i,n-1) cin>>a,G[a].push_back(i+2),G[i+2].push_back(a);
    dfs(1);
    cout<<dp[1]<<"\n";
}