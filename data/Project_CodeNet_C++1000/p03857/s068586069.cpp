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
  int n,k,l; scanf("%d %d %d", &n, &k, &l);
  Union_Find road(n), train(n);
  rep(i,k) {
    ll p,q; scanf("%lld %lld", &p, &q);
    p--,q--;
    road.unite(p,q);
  }

  rep(i,l) {
    ll r,s; scanf("%lld %lld", &r, &s);
    r--,s--;
    train.unite(r,s);
  }

  map<pair<int,int>, int> com;
  vector<pair<int,int>> s(n);
  for (int i = 0; i < n; ++i) {
    s[i].first = road.find(i);
    s[i].second = train.find(i);
    com[s[i]]++;
  }

  rep(i,n) {
    cout << com[s[i]] << " ";
  } END;

}
