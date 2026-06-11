#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll dp[110][400] = {0};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  ll W;
  cin >> N >> W;

  vector<pair<ll, ll>> vec(N);

  ll w, v;
  for(int i = 0; i < N; i++){
    cin >> w >> v;
    vec[i] = make_pair(w, v);
  }

  W = W - vec[0].first * N;
  ll w0 = vec[0].first;
  for(int i = 0; i < N; i++){
    vec[i].first -= w0;
  }

  for(int j = 0; j < 100; j++){
    for(int i = 0; i < 400; i++){
      dp[j][i] = -INF;
    }
  }

  dp[0][0] = 0;

  for(int n = 0; n < N; n++)
  for(int i = 99; i >= 0; i--){
    for(int j = 300; j >= 0; j--){
      if(dp[i][j] >= 0){
        chmax(dp[i+1][j+vec[n].first], dp[i][j] + vec[n].second);
      }
    }
  }

  ll ans = -INF;
  for(int k = 0; k <= N; k++){
    for(int w = 0; w <= min(300LL, W + (N-k) * w0); w++){
      chmax(ans, dp[k][w]);
    }
  }

  cout << ans << endl;

  return 0;
}
