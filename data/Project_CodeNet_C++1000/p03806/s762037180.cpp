#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  int n, ma, mb;
  cin >> n >> ma >> mb;
  vi a(n), b(n), c(n);
  rep(i, n) cin >> a[i] >> b[i] >> c[i];
  int dp[410][410];
  rep(i, 410) rep(j, 410) dp[i][j] = 1e9;
  dp[0][0] = 0;
  rep(k, n) for(int i = 409; i >= 0; i--) for(int j = 409; j >= 0; j--) {
    if(dp[i][j] == 1e9) continue;
    int ni = i + a[k], nj = j + b[k];
    dp[ni][nj] = min(dp[ni][nj], dp[i][j] + c[k]);
  }
  int ans = 1e9;
  rep2(i, 1, 410) rep2(j, 1, 410) if(i * mb == j * ma) ans = min(ans, dp[i][j]);
  cout << (ans == 1e9 ? -1 : ans) << endl;
}