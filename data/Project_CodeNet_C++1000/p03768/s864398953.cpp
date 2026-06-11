#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
int dp[100002][11];
std::vector<int> edge[1000000];
void f(int v,int d,int c){
  if(dp[v][d]||d<0)return;
  dp[v][d]=c;
  for(int p:edge[v])f(p,d-1,c);
  f(v,d-1,c);
}
//main
signed main(){
  int N,M;cin>>N>>M;
  for(int i=0;i<M;i++){
    int a,b;cin>>a>>b;
    a--;b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  memset(dp,0,sizeof(dp));
  int Q;cin>>Q;
  std::vector<int> v(Q),d(Q),c(Q);
  for(int i=0;i<Q;i++)cin>>v[i]>>d[i]>>c[i];
  for(int i=Q-1;i>=0;i--)f(v[i]-1,d[i],c[i]);
  for(int i=0;i<N;i++)cout<<dp[i][0]<<endl;
}
