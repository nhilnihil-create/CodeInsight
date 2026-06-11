#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n; cin >> n;
  map <ll, ll> score;
  rep(i, n) {
    ll a; cin >> a;
    if (score.count(a)) score.at(a)++;
    else score[a] = 1;
  }
  ll max1 = 0, max2 = 0;
  for (auto p : score) {
    if (p.second >= 4) {
      if (max1 < p.first) {
        max1 = p.first;
        max2 = p.first;
      }
    }
    if (p.second >= 2) {
      if (max1 < p.first) {
        max2 = max1;
        max1 = p.first;
      } else if (max2 < p.second) max2 = p.first;
    }
  }
  cout << max1 * max2 << endl;
}