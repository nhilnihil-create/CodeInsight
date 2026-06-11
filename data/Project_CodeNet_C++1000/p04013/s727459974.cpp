#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

constexpr int s_max = 2600;

int main(){
  int n, a;
  cin >> n >> a;
  vector<int> x(n);
  rep(i,n) cin >> x[i];

  vector<vector<ll>> dp(n + 1, vector<ll>(s_max, 0));

  dp[0][0] = 1;

  for (int i = 0; i < n; i++) {
    vector<vector<ll>> ndp(n + 1, vector<ll>(s_max, 0));
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < s_max; k++) {
        ndp[j][k] += dp[j][k]; 
        ndp[j + 1][k + x[i]] += dp[j][k];
      }
    }
    swap(ndp, dp); 
  }

  ll res = 0;

  for (int i = 0; i <= n; i++) {
   res += dp[i][i * a];
  }

  cout << res - 1 << endl;

  return 0;
} 