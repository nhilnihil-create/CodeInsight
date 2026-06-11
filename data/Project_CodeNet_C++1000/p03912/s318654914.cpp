#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n, m;
int x[MAX_N];

map<int, vector<int>> container;
map<int, int> consume;
map<int, int> whole;
set<int> visited;

int ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(x[i]));
  }

  for (int i = 0; i < n; ++i) {
    container[x[i] % m].push_back(x[i]);
  }

  for (auto &e : container) {
    whole[e.first] = e.second.size();

    map<int, int> cnt;

    for (auto &d : e.second) {
      cnt[d] += 1;
    }

    for (auto &d : cnt) {
      consume[e.first] += d.second / 2;
    }
  }

  // for (auto &e : consume) {
  //   printf("p %d: %d\n", e.first, e.second);
  // }

  // for (auto &e : whole) {
  //   printf("c %d: %d\n", e.first, e.second);
  // }

  ans = 0;

  for (auto &e : whole) {
    int key = e.first;
    int opposite_key = (m - key) % m;

    // if (opposite_key > key) continue;
    if (visited.find(key) != visited.end() ||
        visited.find(opposite_key) != visited.end())
      continue;

    visited.insert(key);
    visited.insert(opposite_key);

    if (opposite_key == key) {
      ans += whole[key] / 2;
    } else {
      // if (whole.find(opposite_key) == whole.end()) {
      //   ans += 2 * consume[key];
      //   continue;
      // }

      int x = key;           // bigger
      int y = opposite_key;  // smaller

      if (whole[x] < whole[y]) {
        swap(x, y);
      }

      int diff = abs(whole[x] - whole[y]);
      int actual_consumed_pair = min(diff / 2, consume[x]);

      ans += actual_consumed_pair;  // duplicate pair consume
      ans += whole[y];
    }
  }

  // for (auto &e : container_pair) {
  //   map<int, int> cnt;

  //   for (auto &d: e.second) {
  //     cnt[d.second] += 1;
  //   }

  //   for (auto &d: cnt) {
  //     ans += d.second / 2;
  //   }
  // }

  // for (auto &e : container_pair) {
  //   printf("%d: ", e.first);
  //   for (auto &d : e.second) {
  //     printf("(%d %d) ", d.first, d.second);
  //   }
  //   printf("\n");
  // }

  printf("%d\n", ans);

  return 0;
}
