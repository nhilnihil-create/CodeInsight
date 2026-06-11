#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll dp[5050][5050];

int main(){
  int n;
  string s;
  cin>>n;
  cin>>s;

  dp[0][0]=1;
  for(int k=0;k<n;k++){
      for(int j=0;j<n;j++){
          dp[k+1][j+1]+=2*dp[k][j];
          dp[k+1][j+1]%=MOD;
          if(j==0){
              dp[k+1][j]+=dp[k][j];
              dp[k+1][j]%=MOD;
          }else{
              dp[k+1][j-1]+=dp[k][j];
              dp[k+1][j-1]%=MOD;
          }
      }
  }

  for(int k=1;k<=s.size();k++){
      dp[n][s.size()]=dp[n][s.size()]*(-MOD/2)%MOD;
      dp[n][s.size()]%=MOD;
  }  

  cout<<(dp[n][s.size()]+MOD)%MOD<<endl;

  return 0;
}
