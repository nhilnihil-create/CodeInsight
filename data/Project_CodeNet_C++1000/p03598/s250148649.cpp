#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int N, K;
  cin >> N >> K;

  int ans = 0, x;
  rep(i, 0, N) {
    cin >> x;
    ans += min(x, K - x) * 2;
  }

  cout << ans << endl;

  return 0;
}
