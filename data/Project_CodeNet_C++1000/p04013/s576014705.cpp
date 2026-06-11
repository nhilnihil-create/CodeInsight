#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC044 C - 高橋くんとカード
// 2020.06.16
// dp[i][j][k] := i番目までのカードを見たときに、j枚選んで、合計kとなる組み合わせ

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, A; cin >> N >> A;
  vector<ll> X(N);
  ll sumX = 0;
  REPLL(i, N){
    cin >> X[i];
    sumX += X[i];
  }
  vector<vector<vector<ll> > > dp(N+5, vector<vector<ll> >(N+5, vector<ll>(N*A+5, 0)));
  dp[0][0][0] = 1;
  for(ll i = 0; i < N; i++){
    for(ll j = 0; j <= N; j++){
      for(ll k = 0; k <= N*A; k++){
        dp[i+1][j][k] += dp[i][j][k];
        if(k+X[i] <= N*A) dp[i+1][j+1][k+X[i]] += dp[i][j][k];
      }
    }
  }
  ll ans = 0;
  for(ll i = 1; i <= N; i++){
    ans += dp[N][i][i*A];
  }
  cout << ans << endl;
}