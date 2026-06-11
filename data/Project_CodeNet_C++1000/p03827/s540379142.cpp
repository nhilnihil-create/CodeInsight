#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  int n;
  string s;
  cin >> n >> s;
  int mx = 0;
  int cnt = 0;
  rep(i, 0, n) {
    cnt += (s[i] == 'I' ? 1 : -1);
    mx = max(mx, cnt);
  }
  cout << mx << endl;
  return 0;
}