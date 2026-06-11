#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main(){
  long long dp[55][5000];
  const int G=2500;
    int n,a;
    cin>>n>>a;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin>>x[i],x[i]-=a;
    
    memset(dp,0,sizeof(dp));
    dp[0][G]=1;
    for(int i=0;i<n;i++){
        for(int s=0;s+x[i]<5000;s++){
          if(dp[i][s]==0) continue;
          dp[i+1][s]+=dp[i][s];
          dp[i+1][s+x[i]]+=dp[i][s];
        }
    }
    
    cout<<dp[n][G]-1<<endl;
    return 0;
}
