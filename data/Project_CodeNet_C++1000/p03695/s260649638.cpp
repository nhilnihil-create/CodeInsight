#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin  >> n;
  vector<int> dp(10);
  rep(i,n) {
    int a;
    cin >> a;
    a /= 400;
    if (a >= 8) a = 8;
    dp[a]++;
  }

  int ans = 0;
  for (int i = 0; i <= 7; i++) {
    if (dp[i] > 0) ans++;
  }
  int minans=ans, maxans=ans;
  if (minans == 0 && dp[8] > 0) minans = 1;
  maxans = ans + dp[8];

  cout << minans << " " << maxans << endl;
  return 0;
}