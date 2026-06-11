#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll INF=1000000000;
  ll i,j,k,n,m,r,a,b,c;
  ll x[10];
  cin >> n >> m >> r;
  for(i=0;i<r;i++){
    cin >> x[i];
    x[i]--;
  }
  ll dp[210][210];
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      dp[i][j]=INF;
    }
  }
  for(i=0;i<m;i++){
    cin >> a >> b >> c;
    a--,b--;
    dp[a][b]=c;
    dp[b][a]=c;
  }
  for(k=0;k<n;k++){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  ll y[10];
  for(i=0;i<r;i++){
    y[i]=i;
  }
  ll ans=20000000000000000;
  do{
    ll sum=0;
    for(i=1;i<r;i++){
      sum+=dp[x[y[i-1]]][x[y[i]]];
    }
    if(ans>sum){
      ans=sum;
    }
  }while(next_permutation(y,y+r));
  cout << ans << endl;
  return 0;
}