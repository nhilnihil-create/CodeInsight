#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int main(){
  int N;
  cin >> N;
  string S1,S2;
  cin >> S1 >> S2;
  ll dp[N+1];
  fill((ll*)dp, (ll*)dp + sizeof(dp)/sizeof(ll), 0);
  int flag = 0;
  if(S1[0] != S2[0]) flag = 1;
  if(flag == 1) dp[0] = 6;
  else dp[0] = 3;
  for(int i = 1; i < N; i++){
    if(flag == 1){
      dp[i] = dp[i-1];
      flag = 2;
      continue;
    }
    if(S1[i] == S2[i]){
      if(flag == 0){
	dp[i] = dp[i-1] * 2 % MOD;
      }else{
	dp[i] = dp[i-1];
	flag = 0;
      }
    }else{
      if(flag == 0){
	dp[i] = dp[i-1] * 2 % MOD;
	flag = 1;
      }else{
	dp[i] = dp[i-1] * 3 % MOD;
	flag = 1;
      }
    }
  }
  cout << dp[N-1] << endl;
}
