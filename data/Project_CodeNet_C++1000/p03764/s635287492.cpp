#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  // 入力
  int n, m;
  cin >> n >> m;
  ll x[n], y[m];
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < m; i++) cin >> y[i];

  ll sum_x = 0;
  for (int i = 0; i < n; i++) {
    sum_x += i * x[i] - (n - i - 1) * x[i];
    sum_x %= MOD;
  }
  ll sum_y = 0;
  for (int i = 0; i < m; i++) {
    sum_y += i * y[i] - (m - i - 1) * y[i];
    sum_y %= MOD;
  }

  // 解答
  cout << sum_x * sum_y % MOD << endl;

  return 0;
}
