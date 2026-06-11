#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)

using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 1e6 + 5, MOD = 1e9 + 7;
const int SQ =225;
const long double EPS = 1e-7;
ll dp[N];
ll sum[N];
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  int n;

  cin >> n;

  dp[0] = 1;
  sum[0] = 1;
  for(int i = 1; i <= n; i++){
    dp[i] += dp[i-1];
    if(i >= 3){
      dp[i] += sum[i - 3];
      if(dp[i] >= MOD)dp[i] -= MOD;
    }
    sum[i] = (sum[i-1] + dp[i]) % MOD;
  }
  ll ans = dp[n - 1] * n % MOD;

  if(n >= 2){
    ans += dp[n-2] * (n - 1ll) % MOD *n %MOD;
  }
  ans%=MOD;

  f(i,0,n-2){
    ans+=dp[i]*(i+2ll)%MOD;
    ans+=dp[i]*(n-1ll)%MOD*(n-1ll)%MOD;
    ans%=MOD;
  }
  cout<<ans<<'\n';


  return 0;
}
