#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int n;
vector<vector<int>> g(100010);
vector<int> dp(100010);

int dfs(int v){
  if(g[v].empty()) return dp[v]=0;
  int ret=0;
  vector<int> now;
  for(auto itr:g[v]) now.push_back(dfs(itr));
  sort(begin(now),end(now));
  rep(i,len(now)){
    ret=max(now[i]+(int)len(now)-(int)i,ret);
  }
  return dp[v]=ret;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n;
  FOR(i,2,n+1){
    int a;
    cin>>a;
    g[a].push_back(i);
  }
  cout<<dfs(1)<<endl;
  //FOR(i,1,n+1) cout<<i<<" "<<dp[i]<<endl;
}