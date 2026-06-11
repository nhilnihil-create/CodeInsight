#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

template<typename T>
struct Bit {
  int N; // 2のべき乗でなくてもOK
  vector<T> node;
  Bit(int N) : N(N), node(N + 1, 0) {}
  void add(int i, T w) // node[i] += w
  {
    for (int x = ++i; x <= N; x += x & -x) node[x] += w;
  }
  T sum(int i) // return sum [0, i)
  {
    T ans = 0;
    for (int x = i; x > 0; x -= x & -x) ans += node[x];
    return ans;
  }
  T sum(int i, int j) // return sum [i, j)
  {
    return sum(j) - sum(i);
  }
};

void solve() {
  int N, K;
  cin >> N >> K;
  vector<ll> a(N);
  rep(i, N) cin >> a[i];
  rep(i, N) a[i] -= K;
  dump(a);

  // vector<ll> b(N + 1);
  // b[0] = 0;
  // for (int i = 0; i < N; i++) {
  //   b[i + 1] = b[i] + a[i];
  // }
  vector<ll> b(N);
  b[0] = a[0];
  for (int i = 1; i < N; i++) {
    b[i] = b[i - 1] + a[i];
  }
  dump(b);

  ll ans = 0;
  rep(i, N) if (b[i] >= 0) ans++;

  // 座標圧縮
  map<ll, int> mp;
  rep(i, b.size()) mp[b[i]] = 0;
  int j = 0;
  for (auto& x : mp) x.second = j++;
  rep(i, b.size()) b[i] = mp[b[i]];
  dump(b);

  // Bit<ll> bit(N + 1);
  // bit.add(b[0], 1);
  // for (int i = 1; i <= N; i++) {
  //   ans += bit.sum(b[i] + 1); // 以下なので+1
  //   bit.add(b[i], 1);
  // }
  Bit<ll> bit(N);
  for (int i = 0; i < N; i++) {
    ll s = bit.sum(b[i] + 1); // 以下なので+1
    bit.add(b[i], 1);
    ans += s;
    dump(i, s, ans);
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}