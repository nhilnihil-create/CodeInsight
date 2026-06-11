#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  vector<pair<double, double>> p;
  double price;
  rep(i, 4) {
    cin >> price;
    double volume = 0.25 * (1 << i);
    p.emplace_back(price / volume, volume);
  }
  sort(p.begin(), p.end());
  // rep(i, 4) cerr << p[i].first << ' ' << p[i].second << endl;

  double n;
  cin >> n;
  ll total = 0;
  rep(i, 4) {
    ll price = p[i].first * p[i].second;
    ll num = n / p[i].second;
    total += price * num;
    n -= p[i].second * num;
    // cerr << n << endl;
    if (n == 0) break;
  }
  cout << total << endl;
}
