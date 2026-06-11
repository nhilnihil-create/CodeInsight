#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
vector<int> g[100005];
vector<int> l,r;
void dfs(int u,int p=-1,int d=0){
    l[u]=d;
    for(auto v:g[u]){
        if(v==p)continue;
        dfs(v,u,d+1);
    }
}
void dfs2(int u,int p=-1,int d=0){
    r[u]=d;
    for(auto v:g[u]){
        if(v==p)continue;
        dfs2(v,u,d+1);
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;cin>>n;
  rep(i,n-1){
      int a,b;cin>>a>>b;
      --a,--b;
      g[a].push_back(b);
      g[b].push_back(a);
  }
  l=r=vector<int>(n);
  dfs(0);
  dfs2(n-1);
  int a=0,b=0;
  rep(i,n){
      if(l[i]<=r[i])a++;
      else b++;
  }
  if(a>b)cout<<"Fennec"<<endl;
  else cout<<"Snuke"<<endl;
  return 0;
  }