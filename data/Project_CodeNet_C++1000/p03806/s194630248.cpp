#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n, ma, mb;
  cin >> n >> ma >> mb;
  
  vector<tuple<ll, ll, ll>> yaku(n);
  for (int i = 0; i < n; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    yaku[i] = make_tuple(a, b, c);
  }

  vector<vector<vector<ll>>> dp(41, vector<vector<ll>>(401, vector<ll>(401, INF)));

  dp[0][0][0] = 0;
  for (int i = 1; i < n + 1; i++){
    for (int j = 0; j < 401; j++){
      for (int k = 0; k < 401; k++){
        if (j >= get<0>(yaku[i-1]) && k >= get<1>(yaku[i-1]))
          dp[i][j][k] = min(dp[i-1][j][k], dp[i-1][j-get<0>(yaku[i-1])][k-get<1>(yaku[i-1])] + get<2>(yaku[i-1]));
        else
          dp[i][j][k] = dp[i-1][j][k];
      }
    }
  }

  ll res = INF;
  ll cor = 1;
  while (cor*ma < 401 && cor*mb < 401){
    res = min(res, dp[n][cor*ma][cor*mb]);
    cor++;
  }

  if (res == INF){
    cout << -1 << endl;
  }
  else
    cout << res << endl;

  return 0;
}
