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
#define MAX 110000
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
vector<ll> G[MAX],col(MAX,0);
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
ll dp[300000][12]={};
void solve(ll v,ll d,ll c){
  bool ch=false;
  for(int i=d;i>=0;i--){
    if(dp[v][i] == 0){
      dp[v][i] = c;
      ch = true;
    }
  }
  if(!ch) return;
  if(d==0) return;
  for(auto nv:G[v]){
    solve(nv,d-1,c);
  }
}
signed main(){
  init_io();
  ll n,m,q,a,b;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cin >> q;
  vector<ll> v(q),d(q),c(q);
  for(int i=q-1;i>=0;i--){
    cin >> v[i] >> d[i] >> c[i];
    v[i]--;
  }
  for(int i=0;i<q;i++){
    solve(v[i],d[i],c[i]);
  }
  for(int i=0;i<n;i++){
    cout << dp[i][0]<<endl;
  }
}
