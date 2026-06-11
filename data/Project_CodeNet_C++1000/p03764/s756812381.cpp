#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll MOD = 1e9 + 7;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  ll x[n], y[m];
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int j = 0; j < m; j++) cin >> y[j];
  ll sumx  = 0, sumy = 0;
  for (int i = 1; i < n; i++) {
    sumx += (ll)i * (ll)(n - i) * (x[i] - x[i - 1]);
    sumx %= MOD;
  }
  for (int i = 1; i < m; i++) {
    sumy += (ll)i * (ll)(m - i) * (y[i] - y[i - 1]);
    sumy %= MOD;
  }
  cout << (sumx * sumy) % MOD << endl;
  return 0;
}
