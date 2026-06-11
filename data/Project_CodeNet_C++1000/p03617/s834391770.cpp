#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;
  vector<pair<ll, ll>> cost_per_l(4);
  ll min_one_litter = min(S, min(Q * 4, H * 2));
  ll ans = 0;
  if (2 * min_one_litter < D) {
    ans = N * min_one_litter;
  } else {
    ans = (N / 2) * D + (N % 2) * min_one_litter;
  }
  cout << ans << endl;
  return 0;
}