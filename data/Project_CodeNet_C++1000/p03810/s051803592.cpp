// by newbiechd
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl

const int N_MAX = 200003;
int a[N_MAX];
int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  bool round = 0;
  while (1) {
    round ^= 1;
    int cntO = 0;
    bool flag = 0;
    for (int i = 1; i <= n; ++i)
      cntO += a[i] & 1, flag |= a[i] == 1;
    if (cntO > 1 || flag) {
      cout << (((n - cntO) & 1) == round ? "First" : "Second") << '\n';
      return 0;
    }
    else {
      for (int i = 1; i <= n; ++i)
        if ((a[i] & 1) == 1) {
          --a[i];
          break;
        }
      int g = 0;
      for (int i = 1; i <= n; ++i)
        g = gcd(a[i], g);
      for (int i = 1; i <= n; ++i)
        a[i] /= g;
    }
  }
  return 0;
}
