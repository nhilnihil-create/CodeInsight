#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const ll mod = 1e9+7;

ll dp[2000100];

int main(void){
  ll n;
  cin >> n;
  fill(dp,dp+2000100,1);
  dp[n] = n;
  ll sum = n-1;
  for(int i = n-1;i > 0;--i){
    dp[i] = dp[i+1];
    dp[i] += (n-1)*(n-1);
    dp[i] %= mod;
    dp[i] += sum;
    dp[i] %= mod;
    sum -= dp[i+1+n];
    sum = (sum+mod) % mod;
    sum += dp[i+2];
    sum %= mod;
  }
  cout << dp[1] << endl;
  return 0;
}
