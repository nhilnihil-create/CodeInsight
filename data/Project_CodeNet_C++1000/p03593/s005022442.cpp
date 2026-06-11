#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;

  map<char, int> mp;
  rep(i, 0, h) {
    string a;
    cin >> a;
    rep(j, 0, w) { mp[a[j]]++; }
  }

  if (h % 2 == 0 && w % 2 == 0) {
    for (auto m : mp) {
      if (m.second % 4) {
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
    return 0;
  }

  map<int, int> c;
  for (auto m : mp)
    c[m.second % 4]++;
  if (h & 1 && w & 1) {
    if (c[3] || c[1] != 1)
      cout << "No" << endl;
    else if (c[2] > (h - 1) / 2 + (w - 1) / 2)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
    return 0;
  }

  if (w & 1)
    swap(h, w);
  if (c[1] || c[3])
    cout << "No" << endl;
  else if (c[2] > w / 2)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}
