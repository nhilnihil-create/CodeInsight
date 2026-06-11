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

int N;
map<int, int> mp;

int main() {
  cin >> N;
  rep(i, 0, N) {
    int a;
    cin >> a;
    ++mp[a];
  }

  int ans = 0;
  repe(i, -1, 100001) {
    int cnt = 0;
    cnt += mp[i - 1];
    cnt += mp[i];
    cnt += mp[i + 1];
    chmax(ans, cnt);
  }

  cout << ans;
}
