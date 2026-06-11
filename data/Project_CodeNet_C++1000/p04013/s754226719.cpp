#include<iostream>
using namespace std;
long long dp[55][55*55];
int main(){
  int a,n;
  cin>>n>>a;
  dp[0][0]=1;
  for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    for(int j=i-1;j>=0;j--){
      for(int k=0;k<=55*j;k++){
        dp[j+1][k+x]+=dp[j][k];
      }
    }
  }
  long long ans=0;
  for(int i=1;i<=n;i++) ans+=dp[i][i*a];
    cout<<ans<<endl;
    return 0;
}

