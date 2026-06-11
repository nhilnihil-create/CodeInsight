#include<bits/stdc++.h>

using namespace std;

bool f() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  int x = a - b;
  for (long i = 0; i < n; i++) {
    long ma = i * d - (n - i - 1) * c;
    long mi = i * c - (n - i - 1) * d;
    if (mi <= x && x <= ma) return true;
  }
  return false;
}

int main() {
  if (f()) cout << "YES" << endl;
  else cout << "NO" << endl;
}
    