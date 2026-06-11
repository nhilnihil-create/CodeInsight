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
  ll N, M;
  cin >> N >> M;
  vector<pair<ll, ll>> ab(N), cd(M);
  ll x, y;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    ab[i] = {x, y};
  }
  for (int i = 0; i < M; i++) {
    cin >> x >> y;
    cd[i] = {x, y};
  }
  for (int i = 0; i < N; i++) {
    ll min_l = INF;
    int index;
    for (int j = 0; j < M; j++) {
      ll l = abs(ab[i].first - cd[j].first) + abs(ab[i].second - cd[j].second);
      if (l < min_l) {
        index = j + 1;
        min_l = l;
      }
    }
    cout << index << endl;
  }
  return 0;
}