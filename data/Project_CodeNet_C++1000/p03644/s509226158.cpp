#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
  int ans = -INF;
  int ans_ret = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    int a = i;
    while (true) {
      if (a % 2 == 0) {
        a /= 2;
        ++cnt;
      } else {
        break;
      }
    }
    ans = max(ans, cnt);
    if (cnt >= ans) {
      ans = cnt;
      ans_ret = i;
    }
  }
  cout << ans_ret << endl;
}
