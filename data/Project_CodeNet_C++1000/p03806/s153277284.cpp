#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,A,B,a,b,c; cin>>N>>A>>B;
  vector<vector<vector<ll>>> Z(N+1,vector<vector<ll>>(N*10+1,vector<ll>(N*10+1,4001)));
  Z[0][0][0]=0;
  for(int i=1; i<=N; i++){
    cin>>a>>b>>c;
    for(int j=0; j<=N*10; j++){
      for(int k=0; k<=N*10; k++){
        Z[i][j][k]=min(Z[i-1][j][k],Z[i][j][k]);
        if(j>=a && k>=b) Z[i][j][k]=min(Z[i-1][j-a][k-b]+c, Z[i][j][k]);
      }
    }
  }
  ll ans=4001;
  for(int i=1; i<=N; i++){
    for(int j=0; j<=N*10; j++){
      for(int k=0; k<=N*10; k++){
        if(j%A==0 && k%B==0 && j/A==k/B && j!=0 && k!=0) ans=min(ans,Z[i][j][k]);
      }
    }
  }
  if(ans==4001) ans=-1;
  cout<<ans<<endl;
}