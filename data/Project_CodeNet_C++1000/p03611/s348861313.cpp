#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> dp(1e5+5);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    dp[a]++;
    a++;
    dp[a]++;
    a -= 2;
    if (a >= 0) dp[a]++;
  }
  sort(dp.rbegin(), dp.rend());
  cout << dp[0] << endl;
  return 0;
}