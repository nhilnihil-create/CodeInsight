#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll H, W;
  int N;
  cin >> H >> W >> N;
  set<pair<int, int>> points, events;
  for (int i = 0; i < N; i++) {
    int y, x;
    cin >> y >> x;
    points.insert(make_pair(y, x));
    for (int dy = -2; dy <= 0; dy++) {
      for (int dx = -2; dx <= 0; dx++) {
        events.insert(make_pair(y + dy, x + dx));
      }
    }
  }
  vector<ll> res(10);
  for (auto evt : events) {
    int sy = evt.first, sx = evt.second;
    bool contains = true;
    int cnt = 0;
    for (int dy = 0; dy <= 2; dy++) {
      for (int dx = 0; dx <= 2; dx++) {
        int y = sy + dy, x = sx + dx;
        if (y < 1 || y > H || x < 1 || x > W) {
          contains = false;
          break;
        }
        cnt += points.count(make_pair(y, x));
      }
    }
    if (contains) {
      ++res[cnt];
    }
  }
  res[0] = (H - 2) * (W - 2);
  for (int i = 1; i < 10; i++) {
    res[0] -= res[i];
  }
  for (ll x : res) {
    cout << x << endl;
  }
  return 0;
}
