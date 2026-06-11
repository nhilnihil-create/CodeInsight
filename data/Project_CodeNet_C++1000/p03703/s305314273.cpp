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

#define rep(X, S, E) for (int(X) = (S); (X) < (E); ++(X))
#define rrep(X, S, E) for (int(X) = (E)-1; (X) >= (S); --(X))
#define itrep(X, Y) for (auto(X) = (Y).begin(); (X) != (Y).end(); (X)++)
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
typedef vector<int> vi;
typedef vector<ll> vl;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll INF = 9 * 1e18;
const ll MOD = 1e9 + 7;

template <class T> void mySort(vector<T> &X, bool isAscending) {
  // 昇順
  if (isAscending) {
    sort(all(X));
  } else {
    // 降順
    sort(all(X), greater<T>());
  }
}

class BinaryIndexedTree {
  int N;
  vl bit;

public:
  BinaryIndexedTree(int N) {
    this->N = N;
    bit = vl(N);
  }

  // v[i] += w;
  void add(int i, int w) {
    for (int x = i; x < N; x |= x + 1) {
      bit[x] += w;
    }
  }

  // v[0] + ... + v[a-1]
  int sum(int a) {
    int ret = 0;
    for (int x = a - 1; x >= 0; x = (x & (x + 1)) - 1) {
      ret += bit[x];
    }
    return ret;
  }
};

void solve(long long N, long long K, std::vector<long long> a) {
  vector<pll> acc(N + 1);
  acc[0] = mp(0, 0);
  ll sum = 0;
  rep(i, 0, N) {
    sum += a[i];
    acc[i + 1] = mp(sum - (i + 1) * K, i + 1);
  }

  mySort(acc, true);

  BinaryIndexedTree bit(N + 1);
  ll ans = 0;
  rep(i, 0, N + 1) {
    bit.add(acc[i].sc, 1);
    ans += bit.sum(acc[i].sc);
  }
  print(ans);
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long K;
  scanf("%lld", &K);
  std::vector<long long> a(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  solve(N, K, std::move(a));
  return 0;
}
