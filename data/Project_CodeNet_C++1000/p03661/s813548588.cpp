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

const ll INF = 1e18;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  // 入力
  int N;
  cin >> N;
  ll a[N];
  for (int i = 0; i < N; i++) cin >> a[i];

  // 累積和
  for (int i = 1; i < N; i++) a[i] += a[i-1];

  ll ans = INF;
  for (int i = 0; i < N - 1; i++) {
    ans = min(ans, llabs(a[i] - (a[N-1] - a[i])));
  }

  // 解答
  cout << ans << endl;

  return 0;
}
