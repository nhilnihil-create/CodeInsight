#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;
vector <int> g[N];

int used[N];
int cmp_sz = 0;
bool bad = false;

void dfs(int u) {
  ++cmp_sz;
  for (auto v : g[u]) {
    if (used[v] == -1) {
      used[v] = used[u] ^ 1;
      dfs(v);
    } else if (used[v] != (used[u] ^ 1)) {
      bad = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  fill(used, used + n, -1);
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  for (int i = 0; i < n; ++i) {
    if (used[i] == -1) {
      used[i] = 0;
      cmp_sz = 0;
      bad = false;
      dfs(i);
      if (cmp_sz == 1) ++cnt1;
      else if (!bad) ++cnt2;
      else ++cnt3;
    }
  }
  ll ans = 2LL * cnt1 * n - (ll)cnt1 * cnt1 + 2LL * cnt2 * cnt2 + 2LL * cnt3 * cnt2 + (ll)cnt3 * cnt3;
  cout << ans << '\n';
}

