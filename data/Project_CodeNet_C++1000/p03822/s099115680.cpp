#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define DBG_N(hoge) cerr<<" "<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
vvi E(222222);
ll dp[222222];
ll dfs(ll now,ll par){
  map<ll,ll>MP;
  for(auto a:E[now]){
    if(a==par)continue;
    MP[dfs(a,now)]++;
  }
  if(MP.size()==0)return dp[now]=0;
  else{
    ll num=-1;
    for(auto a:MP)
      num=(a.F>num)?a.F+a.S-1:num+a.S;
    return dp[now]=num+1;
  }
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  for(int i=0;i<n-1;i++){
    ll a;cin>>a;
    E[--a].pb(i+1);
    E[i+1].pb(a);
  }
  fill(dp,dp+222222,llINF);
  cout<<dfs(0,-1)<<endl;
  return 0;
}
