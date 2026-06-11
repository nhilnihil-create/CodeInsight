// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
const ll MOD = 1e9+7;
signed main(){
  init_io();
  ll n,dsum=0;
  cin >> n;
  vector<ll> dp(n+3,0);
  vector<ll> sum(n+3,0);
  dp[1] = n;
  sum[1] = n;
  dp[2] = (n*n)%MOD;
  sum[2] = (n+n*n)%MOD;
  for(int i=3;i<=n;i++){
    dp[i] = (dp[i-1]+(n-1)*(n-1))%MOD;
    dp[i]+=sum[i-3]+(n-1-(i-3));
    dp[i]%=MOD;
    sum[i] = sum[i-1] + dp[i];
    sum[i]%=MOD;
  }
  cout << dp[n] << endl;
}
