#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(X, Y) for (int(X) = 0; (X) < (Y); ++(X))
#define rrep(X, Y) for (int(X) = (Y)-1; (X) >= 0; --(X))
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

class UnionFindTree {
private:
  vector<int> par;
  vector<int> rnk;
  vector<int> siz;

public:
  UnionFindTree(int n) {
    par.assign(n, -1);
    rnk.assign(n, -1);
    siz.assign(n, -1);

    for (int i = 0; i < n; ++i) {
      par[i] = i;
      rnk[i] = 0;
      siz[i] = 1;
    }
  }

  int find(int x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }

  bool same(int x, int y) { return find(x) == find(y); }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (rnk[x] < rnk[y]) {
      par[x] = y;
      siz[y] += siz[x];
    } else {
      par[y] = x;
      siz[x] += siz[y];
      if (rnk[x] == rnk[y])
        ++rnk[x];
    }
  }

  int size(int x) {
    x = find(x);
    return siz[x];
  }
};

void solve(long long N, long long K, long long L, std::vector<long long> p,
           std::vector<long long> q, std::vector<long long> r,
           std::vector<long long> s) {
  map<ll, vector<ll>> roadConnected;
  {
    UnionFindTree uf(N + 1);
    rep(k, K) { uf.unite(p[k], q[k]); }
    rep(n, N) { roadConnected[uf.find(n + 1)].push_back(n + 1); }
  }

  UnionFindTree trainConnected(N + 1);
  rep(l, L) { trainConnected.unite(r[l], s[l]); }

  vector<ll> ans(N + 1);
  for (auto iter = roadConnected.begin(); iter != roadConnected.end(); iter++) {
    vector<ll> sameRoadConnected = iter->second;
    map<ll, ll> cnts;
    for (auto city : sameRoadConnected) {
      cnts[trainConnected.find(city)]++;
    }

    for (auto city : sameRoadConnected) {
      ans[city] = cnts[trainConnected.find(city)];
    }
  }

  rep(n, N) {
    cout << ans[n + 1];
    if (n != N - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long K;
  scanf("%lld", &K);
  long long L;
  scanf("%lld", &L);
  std::vector<long long> p(K);
  std::vector<long long> q(K);
  for (int i = 0; i < K; i++) {
    scanf("%lld", &p[i]);
    scanf("%lld", &q[i]);
  }
  std::vector<long long> r(L);
  std::vector<long long> s(L);
  for (int i = 0; i < L; i++) {
    scanf("%lld", &r[i]);
    scanf("%lld", &s[i]);
  }
  solve(N, K, L, std::move(p), std::move(q), std::move(r), std::move(s));
  return 0;
}
