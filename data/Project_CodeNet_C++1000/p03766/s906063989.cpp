#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <functional>
#include <utility>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
typedef long long int ll;
const ll  MOD = 1000000007;
typedef pair<ll,ll> P;


ll N;
ll dp[1001001];
ll rui_dp[1001001];
ll ans;
int main(){
  cin >> N;
  dp[0] = 1;
  dp[1] = 1;
  rui_dp[0] = 1;
  rui_dp[1] = 1;
  for(int i=1;i<N;i++){
    dp[i+1] += rui_dp[i]+1;
    if(i>=1) dp[i+1] = (dp[i+1]-dp[i-1]+MOD)%MOD;
    rui_dp[i+1] = (rui_dp[i+1]+dp[i+1] + rui_dp[i]) % MOD;
    //cerr << dp[i] << " " << rui_dp[i] << endl;
  }
  if(N==2){
    cout << "4" << endl;
    return 0;
  }
  ll tmp  = ((N-1)*(N-1))%MOD;
  ans =(tmp + N)%MOD;
  tmp = (tmp * rui_dp[N-2])%MOD;
  ans =(ans + tmp) %MOD;
  cerr << ans << endl;
  tmp = ((N-1) * rui_dp[N-1])%MOD;
  ans =(ans + tmp) % MOD;

  cout << ans << endl;
}
