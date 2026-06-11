#include <bits/stdc++.h> 

using namespace std; //ごめんなさい
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,M,R;
  cin>>N>>M>>R;
  vector<int>r(R);
  for(int i=0;i<R;i++)cin>>r[i];
  vector<vector<int>>g(N,vector<int>(N,INT_MAX));
  for(int i=0;i<N;i++)g[i][i]=0;
  for(int i=0;i<M;i++){
    int A,B,C;
    cin>>A>>B>>C;
    A--,B--;
    g[A][B]=C;
    g[B][A]=C;
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(g[i][k]==INT_MAX||g[k][j]==INT_MAX)continue;
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
      }
    }
  }
  sort(rng(r));
  int ans=INT_MAX;
  do{
    int res=0;
    for(int i=0;i<R-1;i++){
      res+=g[r[i]-1][r[i+1]-1];
    }
    ans=min(ans,res);
  }while(next_permutation(rng(r)));
  cout<<ans<<endl;
  return 0;
}
