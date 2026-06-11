#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  ll h, w;
  int n;
  cin >> h >> w >> n;

  map<pii, int> mp;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < 3 && a - j >= 1; j++) {
      for (int k = 0; k < 3 && b - k >= 1; k++) {
        mp[pii(a - j, b - k)]++;
      }
    }
  }

  vector<ll> ans(10);
  ll all = (h - 2) * (w - 2);
  for (auto i : mp) {
    pii p = i.first;
    if (p.first >= 1 && p.first <= h - 2 && p.second >= 1 && p.second <= w - 2) {
      ans[i.second]++;
      all--;
    }
  }
  ans[0] = all;

  for (int i = 0; i < 10; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}