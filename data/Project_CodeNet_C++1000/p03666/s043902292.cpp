#include<bits/stdc++.h>

using namespace std;

long n, a, b, c, d, x;

int g(int m) {
  long ma = m * d - (n - m - 1) * c;
  long mi = m * c - (n - m - 1) * d;
  if (mi <= x && x <= ma) return 2;
  return x > ma;
}

bool f() {
  cin >> n >> a >> b >> c >> d;
  x = a - b;
  int ok = -1, ng = n;
  while (ng - ok > 1) {
    int m = (ok+ng) / 2;
    int r = g(m);
    if (r == 2) return true;
    (r ? ok : ng) = m;
  }
  return false;
}

int main() {
  if (f()) cout << "YES" << endl;
  else cout << "NO" << endl;
}
    