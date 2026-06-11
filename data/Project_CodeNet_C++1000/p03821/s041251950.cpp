#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) {
    cin >> a.at(i);
    cin >> b.at(i);
  }
  ll res = 0;
  per(i, n) {
    int aa = a.at(i);
    int bb = b.at(i);
    ll r = (aa + res) % bb;
    if (r != 0) {
      ll tmp = bb - r;
      res += tmp;
    }
  }
  cout << res << endl;
  return 0;
}
