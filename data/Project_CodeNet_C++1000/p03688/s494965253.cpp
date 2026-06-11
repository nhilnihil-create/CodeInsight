#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  ll N, mi=200000, ma=-1;
  cin >> N;
  vector<ll> a(N);
  map<ll,ll> mp;
  rep(i,N) {
    ll x;
    cin >> x;
    mp[x]++;
    mi = min(mi, x);
    ma = max(ma, x);
  }

  if (mi == ma) {
    // すべてがことなる色（全てのネコがaloneな）とき
    if (mi == N-1) {
      cout << "Yes" << endl;
      return 0;
    }

    // すべてのネコが組になっている場合
    if (mi <= N/2) {
      cout << "Yes" << endl;
      return 0;
    }
  } else if (ma == mi + 1) {
    ll x = mp[mi]; // aloneなネコの数
    ll y = mp[ma]; // 組になっているネコの数

    // ma: 色の種類数
    // 少なくとも1組以上は存在して（x<ma）、なおかつ
    // 組になっているネコの数は2*(ma-x)以上
    if (x < ma && 2*(ma-x) <= y) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
