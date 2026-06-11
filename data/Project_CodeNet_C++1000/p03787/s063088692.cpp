#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
#define int long long
typedef pair<int,int> P;
typedef pair<int,P> PP;

int dfs(int v,vector<int>& used,const vector<vector<int> >& g,int k){
  if(used[v]!=-1){
    return k==used[v];
  }
  used[v]=k;
  int res=1;
  for(int i=0;i<g[v].size();i++){
    if(dfs(g[v][i],used,g,(k+1)%2)==0)res=0;
  }
  return res;
}

signed main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int> > g(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    u--,v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  
  int sum=0;
  int ind=0;
  for(int i=0;i<n;i++){
    if(g[i].size()==0){
	 ind++;
	 sum+=n;
    }
  }
  sum+=(n-ind)*ind;
  
  int cn[2]={};
  vector<int> used(n,-1);
  for(int i=0;i<n;i++){
    if(used[i]!=-1||g[i].size()==0)continue;
    cn[dfs(i,used,g,0)]++;
  }
  
  sum+=cn[1]*cn[1]*2;
  sum+=cn[0]*cn[0];
  sum+=cn[1]*cn[0];
  sum+=cn[0]*cn[1];
  
  cout<<sum<<endl;
  return 0;
}
