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
  char c[2][n];
  rep(i,2)rep(j,n)cin>>c[i][j];
  int x=0;
  bool tate=0,yoko=0;
  int ans=0;
  if(c[0][0]==c[1][0]){
    tate=1;
    ans=3;
    x++;
  }
  else {
    yoko=1;
    ans=6;
    x+=2;
  }
  while(x<n){
    if(c[0][x]==c[1][x]){
      if(tate)ans=ans*2%MOD;
      if(yoko)ans=ans;
      tate=1;yoko=0;
      x++;
    }
    else{
      if(tate)ans=ans*2%MOD;
      if(yoko)ans=ans*3%MOD;
      tate=0;yoko=1;
      x+=2;
    }
  }
  cout<<ans<<endl;
}
