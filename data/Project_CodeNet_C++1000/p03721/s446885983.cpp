#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mod = 1e9 + 7;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> a(n);
  for (auto &i : a) {
    cin >> i.first >> i.second;
  }
  sort(a.begin(), a.end());
  ll c = 0;
  for (int i = 0; i < n; i++) {
    c += a[i].second;
    if (k <= c) {
      cout << a[i].first << endl;
      return 0;
    }
  }
  return 0;
}
