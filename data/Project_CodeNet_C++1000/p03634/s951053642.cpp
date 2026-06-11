#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
struct edge {
    int to, cost;
};

int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}

auto factor(int n){
  map<int,int>res;
  for(int i=2;i*i<=n;i++){
      for(; n%i==0;n/=i) res[i]++;
  }
  if(n>1)res[n]++;
  return res;
}
////////////////////////////////////////////////////////////
  vector<vector<edge>>g(100001,vector<edge>(0));
void dfs(vector<int>&dis,int start){
  for(auto i:g[start]){
    if(dis[i.to]==-1){
      dis[i.to]=dis[start]+i.cost;
      dfs(dis,i.to);
    }
  }
}
signed main() {
  int n;
  cin>>n;
  rep(i,n-1){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    edge e={b,c};
    edge ee={a,c};
    g[a].push_back(e);
    g[b].push_back(ee);
  }
  int q,k;
  cin>>q>>k;
  k--;
  vector<int>d(n,-1);
  d[k]=0;
  dfs(d,k);

  rep(i,q){
    int x,y;
    cin>>x>>y;
    x--;y--;
    cout<<d[x]+d[y]<<endl;
  }
}
