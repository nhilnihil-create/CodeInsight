#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> s(h + 2, vector<char>(w + 2, '#'));
  rep(i, 1, h + 1) rep(j, 1, w + 1) cin >> s[i][j];
  rep(i, 0, h + 2) {
    rep(j, 0, w + 2) { cout << s[i][j]; }
    cout << '\n';
  }
  return 0;
}