#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, m, n) for (int i = m; i < n; ++i)
const int MOD = 1000000007;

string solve2(int N, string s, int a, int b) {
  vector<bool> dp(N+1);
  dp[0] = a;
  dp[1] = b;
  rep(i, 1, N) {
    if(dp[i]) { // オオカミ
      if(s[i] == 'o') dp[i+1] = dp[i-1]^1;
      else dp[i+1] = dp[i-1];
    } else { // ヒツジ
      if(s[i] == 'x') dp[i+1] = dp[i-1]^1;
      else dp[i+1] = dp[i-1];
    }
  }
  int v = 0;
  if(a) {
    if(s[0] == 'o') v = b^1;
    else v = b;
  } else {
    if(s[0] == 'o') v = b;
    else v = b^1;
  }
  string ret = "";
  if(dp[0] == dp[N] && v == dp[N-1]) {
    rep(i, 0, N) {
      ret += dp[i] ? 'W' : 'S';
    }
    return ret;
  } else {
    return "-1";
  }
}

string solve() {
  int N;
  string s;
  cin >> N >> s;
  string ret = "-1";
  rep(i, 0, 2) rep(j, 0, 2) {
    ret = solve2(N, s, i, j);
    if(ret != "-1") return ret;
  }
  return ret;
}

int main() {
  cout << solve() << endl;
  return 0;
}
