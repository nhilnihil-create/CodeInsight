#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, a, b;
  cin >> n >> a >> b;
  
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v.at(i);
  
  sort(v.rbegin(), v.rend());
  
  double sum = 0;
  vector<ll> w;
  for (int i = 0; i < a; i++) {
    sum += v.at(i);
    w.emplace_back(v.at(i));
  }
  
  cout << fixed << setprecision(10) << sum / a << '\n';
  
  ll key = w.back();
  int count1 = 0, count2 = 0;
  for (ll i : w) {
    if (i == key) count1++;
  }
  for (ll i : v) {
    if (i == key) count2++;
  }
  
  vector<vector<ll>> c(52, vector<ll>(52));
  c[0][0] = c[1][0] = c[1][1] = 1;
  for (int i = 0; i <= 50; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) c[i][j] = 1;
      else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }
  
  ll ans = 0;
  if (w.front() != w.back()) ans = c[count2][count1];
  else {
    for (int i = a; i <= b; i++) {
      ans += c[count2][i];
    }
  }
  
  cout << ans << '\n';
}