#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

/* Union-Find-Tree */
class Union_Find {
public:
  vector<long long> par;
  vector<long long> rnk;

  Union_Find (long long n) {
    // par.resize(n), rnk.resize(n);
    for (int i = 0; i < n; ++i) {
      par.pb(i);
      rnk.pb(0);
    }
  }

  // 木の根を求める
  int find(int x) {
    if (par[x] == x)
    return x;
    else
    return par[x] = find(par[x]);
  }

  // xとyの属する集合を併合
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rnk[x] < rnk[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rnk[x] == rnk[y]) rnk[x]++;
    }
  }

  // xとyが同じ集合に属するか否か
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  ll n, k, l; scanf("%lld %lld %lld", &n, &k, &l);
  Union_Find road(n), train(n);

  rep(i,k) {
    int t,s; scanf("%d %d", &t, &s);
    t--, s--;
    if (!road.same(t,s)) road.unite(t,s);
  }

  rep(i,l) {
    int t,s; scanf("%d %d", &t, &s);
    t--, s--;
    if (!train.same(t,s)) train.unite(t,s);
  }

  vector<pair<int, int> > com(n);
  map<pair<int, int>, int> s;
  rep(i,n) {
    com[i].first = road.find(i);
    com[i].second = train.find(i);
    s[com[i]]++;
  }

  rep(i,n) {
    printf("%d ",s[com[i]]);
  }
  END;
}
