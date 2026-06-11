#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  rep(i, n) cin >> t[i];
  int m;
  cin >> m;
  vector<pair<int, int>> v(m);
  rep(i, m) {
    cin >> v[i].first >> v[i].second;
    v[i].first--;
  }
  rep(i, m) {
    int sum = 0;
    rep(j, n) {
      if (v[i].first == j) {
        sum += v[i].second;
      }
      else {
        sum += t[j];
      }
    }
    cout << sum << endl;
  }
  return 0;
}