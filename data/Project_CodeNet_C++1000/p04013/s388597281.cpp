#include <iostream>
#include <vector>
using namespace std;
long long dp[51][51][2501];//i番目j個とったとき和がkになる個数
int main(){
  int N,A;cin>>N>>A;
  vector<int> x(N);
  for(int i = 0; N > i; i++){
    cin>>x[i];
  }
  dp[0][0][0] = 1;
  dp[0][1][x[0]] = 1;
  for(int i = 1; N > i; i++){
    for(int j = 0; i+1 >= j; j++){
      for(int k = 0; 2500 >= k; k++){
        dp[i][j][k] = dp[i-1][j][k];
        if(j && k >= x[i])dp[i][j][k] += dp[i-1][j-1][k-x[i]];
      }
    }
  }
  long long ans = 0;
  for(int j = 1; N >= j; j++){
    ans += dp[N-1][j][j*A];
  }
  cout << ans << endl;
}