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
  ll N;
  cin >> N;
  ll ans = 0;
  vector<ll> x(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i];
    ans += x[i];
  }
  sort(x.begin(), x.end());
  if (ans % 10 == 0) {
    for (int i = 0; i < N; i++) {
      if (x[i] % 10 != 0) {
        ans -= x[i];
        break;
      }
    }
  }
  if (ans % 10 == 0) {
    cout << 0 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}