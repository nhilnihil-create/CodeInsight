#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int W, a, b;
  cin >> W >> a >> b;

  cout << max(0, abs(a - b) - W) << endl;
  return 0;
}