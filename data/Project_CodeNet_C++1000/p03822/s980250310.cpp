// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
#define MAX 110000
vector<ll> G[MAX];
ll dp[MAX]={};
bool used[MAX]={};
ll solve(int v,int prev){
  if(used[v]) return dp[v];
  used[v] = true;
  ll mv=0,res = 0,ndc=0;
  vector<ll> nd;
  for(auto nv:G[v]){
    if(nv!=prev){
      mv = max(mv,solve(nv,v));
      nd.push_back(dp[nv]);
      ndc++;
    }
  }
  if(ndc==0){
    return dp[v] = 1;
  }else{
    sort(nd.begin(),nd.end());
    for(int i=0;i<ndc;i++){
      res = max(res+1,nd[i]+1);
    }
    return dp[v] = res;
  }
}
signed main(){
  init_io();
  ll n;
  cin >> n;
  vector<ll> a(n-1);
  for(int i=0;i<n-1;i++){
    cin >> a[i];
    a[i]--;
    G[i+1].push_back(a[i]);
    G[a[i]].push_back(i+1);
  }
  solve(0,-1);
  for(int i=0;i<n;i++){
//    cout << dp[i]<<" "<<i<<endl;
  }
  cout << dp[0]-1<<endl;
}
