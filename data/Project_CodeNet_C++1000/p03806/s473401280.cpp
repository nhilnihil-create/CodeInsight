#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;
int dp[50][500][500];
int main() {
  int N,Ma,Mb;
  cin>>N>>Ma>>Mb;
  vector<int>a(N),b(N),c(N);
  for(int i=0;i<N;i++){
    cin>>a[i]>>b[i]>>c[i];
  }
  for(int i=0;i<=N;i++){
    for(int j=0;j<=500;j++){
      for(int k=0;k<=500;k++){
        dp[i][j][k]=INF;
      }
    }
  }
  dp[0][0][0]=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<=500;j++){
      for(int k=0;k<=500;k++){
        chmin(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
        chmin(dp[i+1][j][k],dp[i][j][k]);
      }
    }
  }
  int MIN=INF;
  for(int j=1;j<=500;j++){
    for(int k=1;k<=500;k++){
      if(j*Mb==k*Ma){
        chmin(MIN,dp[N][j][k]);
      }
    }
  }
  if(MIN==INF){cout<<-1<<endl;}
  else{cout<<MIN<<endl;}
  return 0;  
}