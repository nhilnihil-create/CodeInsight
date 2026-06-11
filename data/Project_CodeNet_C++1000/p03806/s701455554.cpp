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

const int MAX_A = 420;
const int MAX_B = 420;
const int MAX_N = 41;
int dp[MAX_A][MAX_B][MAX_N];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;

  const int INF32 = 1 << 30;

  for(int i = 0; i < MAX_A; i++){
    for(int j = 0; j < MAX_B; j++){
      for(int k = 0; k < MAX_N; k++){
        dp[i][j][k] = INF32;
      }
    }
  }
  
  dp[0][0][0] = 0;

  int a, b, c;
  for(int i = 0; i < N; i++){
    cin >> a >> b >> c;
    for(int x = 0; x <= 400; x++){
      for(int y = 0; y <= 400; y++){
        chmin(dp[x][y][i+1], dp[x][y][i]);
        chmin(dp[x+a][y+b][i+1], dp[x][y][i] + c);
      }
    }
  }

  int ans = INF32;
  int mul = 1;
  while(Ma * mul  <= 400 && Mb * mul <= 400){
    for(int i = 0; i <= N; i++){
      chmin(ans, dp[Ma * mul][Mb * mul][i]);
    }
    mul++;
  }

  if(ans == INF32){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
  
  return 0;
}
