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
  ll W, H, N;
  cin >> W >> H >> N;
  vector<ll> x(N), y(N), a(N);
  ll min_y = 0, min_x = 0;
  ll max_y = H, max_x = W;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> a[i];
    switch (a[i]) {
      case 1:
        if (min_x < x[i] && x[i] < max_x) {
          min_x = x[i];
        } else if (x[i] >= max_x) {
          cout << 0 << endl;
          return 0;
        }
        break;
      case 2:
        if (min_x < x[i] && x[i] < max_x) {
          max_x = x[i];
        } else if (min_x >= x[i]) {
          cout << 0 << endl;
          return 0;
        }
        break;
      case 3:
        if (min_y < y[i] && y[i] < max_y) {
          min_y = y[i];
        } else if (y[i] >= max_y) {
          cout << 0 << endl;
          return 0;
        }
        break;
      case 4:
        if (min_y < y[i] && y[i] < max_y) {
          max_y = y[i];
        } else if (min_y >= y[i]) {
          cout << 0 << endl;
          return 0;
        }
        break;
      default:
        break;
    }
  }
  ll ans = max((max_x - min_x) * (max_y - min_y), 0LL);
  cout << ans << endl;
  return 0;
}