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
  ll N, K;
  cin >> N >> K;
  ll ans = 0;
  ll x;
  for (int i = 0; i < N; i++) {
    cin >> x;
    ans += min(2 * x, 2 * (K - x));
  }
  cout << ans << endl;
  return 0;
}