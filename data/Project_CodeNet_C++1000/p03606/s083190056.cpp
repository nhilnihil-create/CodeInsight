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
  int N;
  cin >> N;
  int ans = 0, l, r;
  rep(i, 0, N) {
    cin >> l >> r;
    ans += r - l + 1;
  }

  cout << ans << endl;

  return 0;
}
