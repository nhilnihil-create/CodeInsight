#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int X, t;
  cin >> X >> t;

  cout << max(0, X - t) << endl;
  return 0;
}