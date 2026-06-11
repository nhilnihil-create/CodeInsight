#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> v(n), acc(n);
  rep(i, 0, n) {
    cin >> v[i];
    if (i == 0)
      acc[i] = v[i];
    else
      acc[i] = acc[i - 1] + v[i];
  }

  ll cor = 0, a1 = 0, a2 = 0;
  rep(i, 0, n) {
    ll add = abs(acc[i] + cor) + 1;
    if (i & 1 && acc[i] + cor >= 0) {
      a1 += add;
      cor -= add;
    } else if (!(i & 1) && acc[i] + cor <= 0) {
      a1 += add;
      cor += add;
    }
  }

  cor = 0;
  rep(i, 0, n) {
    ll add = abs(acc[i] + cor) + 1;
    if (i & 1 && acc[i] + cor <= 0) {
      a2 += add;
      cor += add;
    } else if (!(i & 1) && acc[i] + cor >= 0) {
      a2 += add;
      cor -= add;
    }
  }
  cout << min(a1, a2) << endl;
}
