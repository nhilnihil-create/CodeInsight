#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1e9;

int main() {
  int n, k, x, y, res;
  cin >> n >> k >> x >> y;
  if (n > k) {
    res = x*k + y*(n-k);
  } else {
    res = x*n;
  }
  cout << res << endl;
}
