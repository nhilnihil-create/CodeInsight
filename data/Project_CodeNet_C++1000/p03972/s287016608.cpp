#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
  int W, H;
  cin >> W >> H;
  vector<pair<ll, int>> es;
  for (int i = 0; i < W; i++) {
    ll p;
    cin >> p;
    es.emplace_back(p, 0);
  }
  for (int i = 0; i < H; i++) {
    ll q;
    cin >> q;
    es.emplace_back(q, 1);
  }
  sort(es.begin(), es.end());
  ll res = 0;
  vector<int> rem(2, 0);
  rem[0] = W + 1;
  rem[1] = H + 1;
  for (auto e: es) {
    ll p = e.first;
    int t = e.second;
    res += rem[t^1] * p;
    --rem[t];
  }
  cout << res << endl;
  return 0;
}
