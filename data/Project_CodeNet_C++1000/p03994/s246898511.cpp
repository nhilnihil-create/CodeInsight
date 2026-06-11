#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

typedef long long ll;
ll MOD = 1000000007;

// a^p
// 2^3 = 2 * 2^2
// 2^2 = 2 * (2^1)
// 2^1 = 2
ll modpow(ll a, ll p, ll mod) {
  if (p == 0)
    return 1;

  if (p % 2 == 0) {
    ll half = modpow(a, p / 2, mod) % mod;
    return half * half % mod;
  } else {
    return a * modpow(a, p - 1, mod) % mod;
  }
}

// nCa を求める
ll modCombination(ll n, ll a, ll mod) {
  if (n - a < a) {
    return modCombination(n, n - a, mod);
  }

  ll denominator = 1; // 分母
  ll numerator = 1;   // 分子

  for (ll i = 0; i < a; i++) {
    denominator *= a - i;
    numerator *= n - i;
    denominator %= mod;
    numerator %= mod;
  }

  return numerator * modpow(denominator, mod - 2, mod) % mod;
}

class UnionFind {
private:
  vector<ll> parents;

public:
  UnionFind(ll n) : parents(n, -1) {}

  bool issame(ll x, ll y) {
    return root(x) == root(y);
  }

  bool merge(ll x, ll y) {
    if (issame(x, y))
      return false;

    ll rx = root(x);
    ll ry = root(y);
    if (parents[rx] > parents[ry])
      swap(rx, ry);
    // サイズ情報を更新
    parents[rx] += parents[ry];
    // yの親を更新
    parents[ry] = rx;

    return true;
  }

  ll size(ll x) {
    return -parents[root(x)];
  }

private:
  ll root(ll x) {
    if (parents[x] < 0)
      return x;
    // 根の親の値に木の(-)サイズの情報を入れる
    return parents[x] = root(parents[x]);
  }
};

int main() {
  string s;
  cin >> s;
  ll K;
  cin >> K;

  ll remain = K;
  string ans = s;
  for (ll i = 0; i < s.size(); i++) {
    const char c = s[i];
    ll n = (ll)('z' - c + 1) % 26;

    if (remain >= n) {
      remain -= n;
      ans[i] = 'a';
    }

    if (i == s.size() - 1 && remain > 0) {
      ans[i] = (char)('a' + (ans[i] + remain - 'a') % 26);
    }
  }

  cout << ans << endl;
  return 0;
}
