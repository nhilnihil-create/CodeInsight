#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <memory>
#include <deque>
#include <set>
#include <unordered_set>
#include <cmath>
#include <list>
#include <cassert>
#include <cstring>

using namespace std;

using big = long long;

const int N = 200009;


int f[N], g[N];
int ans[N];
set<int> fs[N], gs[N];

int gf(int fa[], int x) {
  if (fa[x] != x) {
    fa[x] = gf(fa, fa[x]);
  }
  return fa[x];
}

int main() {
	std::ios_base::sync_with_stdio(false);
  int n, K, L;
  cin >> n >> K >> L;
  for (int i = 1; i <= n; ++i) {
    f[i] = g[i] = i;
  }
  while (K--) {
    int x, y;
    cin >> x >> y;
    f[gf(f, x)] = gf(f, y);
  }
  while (L--) {
    int x, y;
    cin >> x >> y;
    g[gf(g, x)] = gf(g, y);
  }

  for (int i = 1; i <= n; ++i) {
    fs[gf(f, i)].insert(i);
    gs[gf(g, i)].insert(i);
  }
  for (int i = 1; i <= n; ++i) {
    if (!ans[i]) {
      int x = gf(f, i);
      int y = gf(g, i);
      auto *s1 = &fs[x];
      auto *s2 = &gs[y];
      if (s1->size() > s2->size()) {
        swap(s1, s2);
      }
      vector<int> inter;
      for (int t : *s1) {
        if (s2->count(t)) {
          inter.push_back(t);
        }
      }
      for (int t : inter) {
        ans[t] = inter.size();
      }
    }
  }
  for (int i = 1; i  <= n; ++i) {
    if (i > 1) {
      cout << " ";
    }
    cout << ans[i];
  }
}
