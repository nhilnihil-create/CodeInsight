#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

vector<vector<int> > G(101010);
int N;
ll A[101010];

void bad(){
  cout<<"NO\n";
  exit(0);
}

int dfs(int v,int p){
  ll sum=0, ma=0;
  for(auto u:G[v]) if(u!=p){
    ll tmp=dfs(u,v);
    ma=max(ma,tmp);
    sum+=tmp;
  }
  if(p==-1){
    if(G[v].size()==1){
      if(A[v]!=sum) bad();
    }else{
      if(2*A[v]!=sum) bad();
    }
  }else{
    if(G[v].size()==1) return A[v];
    ll ret=2*A[v]-sum;
    sum+=ret;
    ma=max(ma,ret);
    // ma>sum/2であると自己ループが発生する
    if(ret<0||2*ma>sum) bad();
    else return ret;
  }
  return 0;
}

int main(){
  cin>>N;
  rep(i,N) cin>>A[i];
  rep(i,N-1){
    int a,b; cin>>a>>b; a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(0,-1);
  cout<<"YES\n";
  return 0;
}
