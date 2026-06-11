#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll h, w, ans = 0;
  cin >> h >> w;
  string s[h];
  rep(i, h) cin >> s[i];
  unordered_map<char, ll> mp;
  rep(i, h) rep(j, w) mp[s[i][j]]++;

  if (h % 2 == 0 && w % 2 == 0) {
    bool ok = true;
    for (auto m : mp)
      if (m.second % 4) ok = false;
    cout << (ok ? "Yes" : "No") << endl;
  } else if (h % 2 && w % 2) {
    map<ll, ll> c;
    for (auto m : mp) c[m.second % 4]++;
    if (c[3] || c[1] != 1 || c[2] > (h - 1) / 2 + (w - 1) / 2)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  } else {
    if (w % 2) swap(h, w);
    map<int, int> c;
    for (auto m : mp) c[m.second % 4]++;

    if (c[1] || c[3] || c[2] > w / 2)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }

  return 0;
}
