#include<iostream>
using namespace std;

long long dp[51][2560] = {0};
 
int main(){
  int N, A;
  cin >> N >> A;
  
  dp[0][0] = 1;
  for (int i = 1; i <= N; i ++){
    int x;
    cin >> x;
    for (int j = i - 1; j >= 0; j --){
      for (int k = 0; k <= 2501; k ++){
        dp[j + 1][k + x] += dp[j][k];
      }
    }
  }
  
  
  long long totalWays = 0;
  for (int i = 1; i <= N; i ++){
    totalWays += dp[i][i * A];
  }
  
  cout << totalWays << '\n';
  
}
