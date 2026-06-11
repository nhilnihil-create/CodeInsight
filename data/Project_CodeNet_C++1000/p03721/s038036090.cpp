#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());
  ll count = 0;
  rep(i, n) {
    count += v[i].second;
    if (count >= k) {
      cout << v[i].first << endl;
      break;
    }
  }
  return 0;
}