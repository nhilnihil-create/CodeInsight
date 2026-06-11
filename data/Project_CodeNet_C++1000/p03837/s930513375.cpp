#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,M,a,b,c,ans=0; cin>>N>>M;
  vector<vector<ll>>Z(N+1,vector<ll>(N+1,1e9)), Q(N+1,vector<ll>(N+1,1e9));
  for(int i=1; i<=M; i++){
    cin>>a>>b>>c;
    Z[a][b]=c;
    Z[b][a]=c;
  }
  for(int i=1; i<=N; i++){Z[i][i]=0;}
  Q=Z;
  for(int k=1; k<=N; k++){
    for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
        Z[i][j]=min(Z[i][j],Z[i][k]+Z[k][j]);
      }
    }
  }
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      if(Z[i][j]!=Q[i][j] && Q[i][j]!=1e9){
        ans++;
//        cout<<"i:"<<i<<" j:"<<j<<" Z:"<<Z[i][j]<<" Q:"<<Q[i][j]<<endl;
      }
    }
  }
  cout<<ans/2<<endl;
}