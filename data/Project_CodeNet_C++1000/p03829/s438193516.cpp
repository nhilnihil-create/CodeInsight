#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC052 D - Walk and Teleport

ll INF = 1e18;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, A, B; cin >> N >> A >> B;
  vector<ll> X(N, 0);
  REPLL(i, N){
    cin >> X[i];
  }
  
  vector<ll> dp(N+1, INF);
  dp[0] = 0;
  dp[1] = 0;
  for(ll i = 1; i < N; i++){
    chmin(dp[i+1], min(dp[i]+(X[i]-X[i-1])*A ,dp[i]+B));
  }
  cout << dp[N] << endl;
}