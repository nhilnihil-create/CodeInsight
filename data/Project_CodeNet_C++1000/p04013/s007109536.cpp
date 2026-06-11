#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <set>
#include <string.h>

using namespace std;

typedef long long ll;

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REP3(i,st,en) for(ll (i)=(st);(i)<(en);(i)++)

using P = pair<ll, ll>;
const int MOD = 1e9+7;
const ll INF = 1e+14;
const double PI = 3.14159265349;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, A;
  cin >> N >> A;
  vector<ll> x(N);
  ll lb=0;
  ll ub=0;
  REP(i,N) {
    ll xi;
    cin >> xi;
    x[i] = xi - A;
    if (x[i]<0){
      lb += x[i];
    } else if (x[i]>0){
      ub += x[i];
    }
  }

  // dp
  vector<vector<ll>> dp(N+1, vector<ll>(ub-lb+1,0));
  dp[0][0-lb] = 1;

  REP(i, N){
    ll xi = x[i];
    REP(j, ub-lb+1){
      if (j+xi<ub-lb+1 && j+xi>=0){
        dp[i+1][j+xi] += dp[i][j];
      }
      dp[i+1][j] += dp[i][j]; // not pick x[i]
    }
  }
  
  cout << dp[N][0-lb]-1 << "\n";
  return 0;
}
