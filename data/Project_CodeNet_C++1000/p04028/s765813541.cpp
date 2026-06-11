#include<bits/stdc++.h>
using namespace std;
long long DP[5005][5005];
int po=5e8+4;
int mod=1e9+7;
int main(){
  int N;
  string S;
  cin>>N>>S;
  DP[0][0]=1;
  for(int i=1;i<N+1;i++){
    (DP[i][0]=DP[i-1][1]+DP[i-1][0])%=mod;
    for(int j=1;j<N+1;j++){
      (DP[i][j]=DP[i-1][j-1]*2+DP[i-1][j+1])%=mod;
    }
  }
  long long ans=DP[N][S.size()];
  for(int i=0;i<S.size();i++){
    (ans*=po)%=mod;
  }
  cout<<ans<<endl;
  return 0;
}
  
