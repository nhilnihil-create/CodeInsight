#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

vector<int> g[100010];
int n,m,q;
int dp[100010][11];

void dfs(int v,int d,int c){
  if(d<0||dp[v][d]) return;

  dp[v][d]=c;
  for(auto to:g[v]){
    dfs(to,d-1,c);
  }
  return;
}


int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  cin>>q;
  int v[q],d[q],c[q];
  for(int i=0;i<q;i++){
    cin>>v[i]>>d[i]>>c[i];
  }

  for(int i=q-1;i>=0;i--){
    for(int j=d[i];j>=0;j--){
      dfs(v[i],j,c[i]);
    }
  }

  for(int i=1;i<=n;i++){
    cout<<dp[i][0]<<endl;
  }

  return 0;
}
