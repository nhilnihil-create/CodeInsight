#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> dp(n+5);
  rep(i,m) {
    int a,b;
    cin >> a >> b;
    dp[a]++;
    dp[b]++;
  }
  for (int i = 1; i <= n; i++){
    cout << dp[i] << endl;
  }
  return 0;

}