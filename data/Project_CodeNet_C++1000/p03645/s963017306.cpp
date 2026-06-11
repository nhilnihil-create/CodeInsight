#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

int N, M;
set<int> to1, ton;

int main() {
  cin >> N >> M;
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
      to1.insert(b);
    }
    if (b == N) {
      ton.insert(a);
    }
  }

  for (auto e : ton) {
    if (e == 1) {
      continue;
    }
    if (to1.count(e) == 1) {
      cout << "POSSIBLE";
      return 0;
    }
  }

  cout << "IMPOSSIBLE";
}
