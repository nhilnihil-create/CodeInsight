#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)

const int N = 2e5 + 5;

struct dsu {
  int sz[N], par[N];
  int n;
  dsu(int _n) : n(_n) {
    fill(sz+1, sz+1+n, 1);
    memset(par, 0, sizeof par);
    iota(par+1, par+1+n, 1);
  }
  int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
  }
  int unite(int u, int v) {
    u = find(u);
    v = find(v);
    if(u != v) {
      if(sz[u] > sz[v]) swap(u, v);
      sz[v] += sz[u];
      par[u] = v;
      return 1;
    } return 0;
  }
};

int n, k, l;

int main(int argc, char const *argv[])
{
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  scanf("%d %d %d", &n, &k, &l);
  dsu road(n), rail(n);
  for(int i = 0; i < k; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    road.unite(u, v);
  }
  for(int i = 0; i < l; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    /*if(road.find(u) == road.find(v)) {
      rail.unite(u, v);
    }*/
    rail.unite(u, v);
  }
  map<ii, int> cnt;
  for(int i = 1; i <= n; ++i) {
    cnt[ii(road.find(i), rail.find(i))]++;
  }
  for(int i = 1; i <= n; ++i) {
    // printf("%d ", rail.sz[rail.find(i)]);
    printf("%d ", cnt[ii(road.find(i), rail.find(i))]);
  }
  puts("");
  return 0;
}