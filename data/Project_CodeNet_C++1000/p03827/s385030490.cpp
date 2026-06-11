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
  string s;
  cin >> n >> s;
  int res = 0;
  int tmp = 0;
  rep(i, n) {
    char c = s[i];
    if (c == 'I') {
      tmp++;
    } else if (c == 'D') {
      tmp--;
    }
    res = max(res, tmp);
  }
  cout << res << endl;
  return 0;
}
