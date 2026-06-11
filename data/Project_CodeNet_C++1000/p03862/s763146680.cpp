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
  ll N, x;
  cin >> N >> x;
  vector<ll> a(N);
  ll ans = 0;
  ll prev_v;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (a[i] > x) {
      prev_v = a[i];
      a[i] = x;
      ans += prev_v - a[i];
    }
  }
  for (int i = 0; i < N - 1; i++) {
    if (a[i] + a[i + 1] <= x) continue;
    prev_v = a[i + 1];
    a[i + 1] = prev_v - ((a[i] + a[i + 1]) - x);
    ans += prev_v - a[i + 1];
  }
  cout << ans << endl;
  return 0;
}