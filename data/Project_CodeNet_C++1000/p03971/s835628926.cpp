#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, a, b;
  string s;
  cin >> n >> a >> b;
  cin >> s;
  int aa = 0;
  int bb = 0;
  rep(i, n) {
    bool ok = false;
    char c = s.at(i);
    if (c == 'a') {
      if (aa + bb < a + b) {
        ok = true;
        aa++;
      }
    } else if (c == 'b') {
      if (aa + bb < a + b && bb < b) {
        ok = true;
        bb++;
      }
    } else {
      // false のまま
    }
    cout << (ok ? "Yes" : "No") << endl;
  }
  return 0;
}
