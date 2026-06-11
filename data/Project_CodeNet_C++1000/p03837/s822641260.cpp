#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,M;
  cin>>N>>M;
  vector<vector<int>>d(N,vector<int>(N,INT_MAX/3));
  for(int i=0;i<N;i++)d[i][i]=0;
  struct E{
    int from,to,cost;
  };
  vector<E>e(M);
  for(int i=0;i<M;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    d[a][b]=c;
    d[b][a]=c;
    e[i]={a,b,c};
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  int ans=0;
  for(int i=0;i<M;i++){
    if(d[e[i].from][e[i].to]!=e[i].cost)ans++;
  }
  cout<<ans<<endl;

  return 0;
}
